#!/usr/bin/env python
# coding: utf-8

#------------------------- 1. Import Necessary Libraries -------------------------

import sys
import nltk
import sklearn
import pandas as pd
import numpy as np
from sklearn.preprocessing import LabelEncoder
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize

# we can split the featuresets into training and testing datasets using sklearn
from sklearn import model_selection

# We can use sklearn algorithms in NLTK
from nltk.classify.scikitlearn import SklearnClassifier
from sklearn.svm import SVC

from sklearn.neighbors import KNeighborsClassifier
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.linear_model import LogisticRegression, SGDClassifier
from sklearn.naive_bayes import MultinomialNB
from sklearn.svm import SVC
from sklearn.metrics import classification_report, accuracy_score, confusion_matrix

# Ensemble methods - Voting classifier
from sklearn.ensemble import VotingClassifier


print("\n-----------Necessary Libraries are imported----------\n")


#------------------------- 2. Preprocessing the Dataset ------------------------

# load the dataset of SMS messages
df = pd.read_table("SMSSpamCollection", header=None, encoding='utf-8')

classes = df[0]

print("\n----------Successfully loaded the dataset----------\n")

# convert class labels to binary values, 0 = ham and 1 = spam
encoder = LabelEncoder()
Y = encoder.fit_transform(classes)


# store the SMS message data
text_messages = df[1]


# use regular expressions to replace email addresses, URLs, phone numbers, other numbers

# Replace 10 digit phone numbers (formats include paranthesis, spaces, no spaces, dashes) with 'phonenumber'
processed = text_messages.str.replace(r'^\(?[\d]{3}\)?[\s-]?[\d]{3}[\s-]?[\d]{4}$',
                                  'phonenumbr',regex=True)

# Replace email addresses with 'email'
processed = processed.str.replace(r'^.+@[^\.].*\.[a-z]{2,}$',
                                 'emailaddress',regex=True)

# Replace URLs with 'webaddress'
processed = processed.str.replace(r'^http\://[a-zA-Z0-9\-\.]+\.[a-zA-Z]{2,3}(/\S*)?$',
                                  'webaddress',regex=True)

# Replace money symbols with 'moneysymb' (£ can by typed with ALT key + 156)
processed = processed.str.replace(r'£|\$', 'moneysymb',regex=True)
    
    
# Replace numbers with 'numbr'
processed = processed.str.replace(r'\d+(\.\d+)?', 'numbr',regex=True)

# Remove punctuation
processed = processed.str.replace(r'[^\w\d\s]', ' ',regex=True)

# Replace whitespace between terms with a single space
processed = processed.str.replace(r'\s+', ' ',regex=True)

# Remove leading and trailing whitespace
processed = processed.str.replace(r'^\s+|\s+?$', '',regex=True)


# change words to lower case - Hello, HELLO, hello are all the same word
processed = processed.str.lower()


# remove stop words from text messages

stop_words = set(stopwords.words('english'))

processed = processed.apply(lambda x: ' '.join(
    term for term in x.split() if term not in stop_words))


# Remove word stems using a Porter stemmer
ps = nltk.PorterStemmer()

processed = processed.apply(lambda x: ' '.join(
    ps.stem(term) for term in x.split()))

print("\n----------Preprocessing is completed----------\n")


#------------------------- 3. Generating Features ------------------------


# create bag-of-words
all_words = []

for message in processed:
    words = word_tokenize(message)
    for w in words:
        all_words.append(w)
        
all_words = nltk.FreqDist(all_words)


# use the 1500 most common words as features
word_features = list(all_words.keys())[:1500]

print("\n----------Features are generated----------\n")

# The find_features function will determine which of the 1500 word features are contained in the review
def find_features(message):
    words = word_tokenize(message)
    features = {}
    for word in word_features:
        features[word] = (word in words)

    return features


# Now lets do it for all the messages
messages = list(zip(processed, Y))

# define a seed for reproducibility
seed = 1
np.random.seed = seed
np.random.shuffle(messages)

# call find_features function for each SMS message
featuresets = [(find_features(text), label) for (text, label) in messages]

# split the data into training and testing datasets
training, testing = model_selection.train_test_split(featuresets, test_size = 0.25, random_state=seed)



#------------------------------- 4. Scikit-Learn Classifiers with NLTK -----------------------------


# Define models to train
names = ["K Nearest Neighbors", "Decision Tree", "Random Forest", "Logistic Regression", "SGD Classifier",
         "Naive Bayes", "SVM Linear"]

classifiers = [
    KNeighborsClassifier(),
    DecisionTreeClassifier(),
    RandomForestClassifier(),
    LogisticRegression(),
    SGDClassifier(max_iter = 100),
    MultinomialNB(),
    SVC(kernel = 'linear')
]

models = list(zip(names, classifiers))

for name, model in models:
    nltk_model = SklearnClassifier(model)
    nltk_model.train(training)
    accuracy = nltk.classify.accuracy(nltk_model, testing)*100
    print("{} Accuracy: {}".format(name, accuracy))


# Ensemble methods - Voting classifier
from sklearn.ensemble import VotingClassifier

nltk_ensemble = SklearnClassifier(VotingClassifier(estimators = models, voting = 'hard', n_jobs = -1))
nltk_ensemble.train(training)
accuracy = nltk.classify.accuracy(nltk_model, testing)*100
print("Voting Classifier Accuracy: {} \n".format(accuracy))


# make class label prediction for testing set
txt_features, labels = zip(*testing)

prediction = nltk_ensemble.classify_many(txt_features)


# print classification report and confusion matrix  
print("\n----------Classification report----------\n")
print(classification_report(labels, prediction))

print("\n----------Confusion matrix----------\n")
df=pd.DataFrame(
    confusion_matrix(labels, prediction),
    index = [['Actual', 'Actual'], ['Ham', 'Spam']],
    columns = [['Predicted', 'Predicted'], ['Ham', 'Spam']])
print(df)




