
class Node:
    def __init__(self,parent):
        self.symb=''
        self.left = None
        self.right = None
        self.parent = parent

    def isLeaf(self):
        return (self.left == None) and (self.right == None)

def rec_pre(currnode, firstseq, scndseq, i,j):
    if firstseq[i]=='1':
        left,right=Node(currnode),Node(currnode)
        currnode.left = left
        currnode.right = right
        rec_pre(left,firstseq,scndseq,i+1,j)
    else: # currnode is a leaf. Set its symb attr
        currnode.symb = scndseq[j]

        while (currnode.parent != None) and (currnode.parent.right == currnode):
            currnode = currnode.parent

        if currnode.parent == None:
        	return

        currnode = currnode.parent.right
        rec_pre(currnode,firstseq,scndseq,i+1,j+1)
        

def unflatten(seq1,seq2):
    root = Node(None)
    rec_pre(root,seq1,seq2,0,0)
    return root

def build_code_dict(node,dic,codeword):
    if node.isLeaf():
    	dic[codeword]=node.symb
    else:
    	build_code_dict(node.left,dic,codeword+'0')
    	build_code_dict(node.right,dic,codeword+'1')

def huffman_decode(code,dic):
    ans=''
    i=0
    while i < len(code):
      word = code[i]
      while word not in dic:
        i=i+1
        if i == len(code):
            print("ERROR")
            return
        
        word=word+code[i]

      #print(dic[word],end='')
      ans=ans+dic[word]
      i = i+1

    #print()
    return ans

def main():
    #if len(sys.argv) not in [2, 3]:
    #    return

    #fname = sys.argv[1]
    file = open('output.txt', 'r')

    seq1 = file.readline().strip()
    seq2 = file.readline().strip()
    code = file.readline().strip()
    
    node = unflatten(seq1,seq2)
    dic = {}
    build_code_dict(node,dic,'')
    print('Encoding dictionary: ',dic)
    print('Original Text: ',end='') 
    print(huffman_decode(code,dic))

    file.close()

if __name__ == '__main__':
    main()
