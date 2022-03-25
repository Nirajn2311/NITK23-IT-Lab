let timeRem = 10;

let selectedAnimals = new Array(16).fill(0);
const allAnimals = [
  'Dog',
  'Cat',
  'Camel',
  'Lion',
  'Tiger',
  'Bear',
  'Elephant',
  'Monkey',
  'Rabbit',
  'Panda',
  'Horse',
  'Cow',
  'Goat',
  'Sheep',
  'Chicken',
  'Duck',
];
const userAnimals = allAnimals.sort(() => 0.5 - Math.random()).slice(0, 9);

document.getElementById('animal-list').innerHTML = userAnimals
  .map((animal, index) => {
    return `<li id="selected-animal-${index}">${animal}</li>`;
  })
  .join('');

document.getElementById('all-animal-list').innerHTML = allAnimals
  .sort(() => 0.5 - Math.random())
  .map((animal, index) => {
    return `<li id="animal-${index}">${animal}</li>`;
  })
  .join('');

for (i = 0; i < allAnimals.length; i++) {
  document.getElementById(`animal-${i}`).addEventListener('click', e => {
    selectedAnimals[e.target.id.split('-')[1]] =
      +!selectedAnimals[e.target.id.split('-')[1]];
    e.target.classList.toggle('selected');
    if (document.getElementById('error').style.display === 'block') {
      document.getElementById('error').style.display = 'none';
    }
  });
}

function startExperiment() {
  document.getElementById('page-1').style.display = 'none';
  document.getElementById('page-2').style.display = 'block';
  let timeRemTimer = setInterval(() => {
    timeRem--;
    document.getElementById('rem-time').innerHTML = timeRem;
    if (timeRem <= 0) {
      clearInterval(timeRemTimer);
      document.getElementById('page-2').style.display = 'none';
      document.getElementById('page-3').style.display = 'block';
    }
  }, 1000);
}

function results() {
  if (document.querySelectorAll('.selected').length > 9) {
    document.getElementById('error').style.display = 'block';
    document.getElementById('error-msg').innerHTML =
      'You should select maximum 9 animals';
    return;
  }
  let top = 0,
    middle = 0,
    bottom = 0;
  for (i = 0; i < userAnimals.length; i++) {
    let ind = allAnimals.indexOf(userAnimals[i]);
    let listItem = document.createElement('li');
    if (selectedAnimals[ind] === 1) {
      if (i < 3) {
        top++;
      } else if (i < 6) {
        middle++;
      } else {
        bottom++;
      }
      listItem.innerHTML = userAnimals[i];
      listItem.classList.add('selected');
    } else {
      listItem.innerHTML = userAnimals[i];
    }
    document.getElementById('recall-list').appendChild(listItem);
  }
  if (top + middle + bottom === 9) {
    document.getElementById('results').innerHTML =
      'Results are in accordance with Serial Position Effect as more items from top and bottom were recalled. Also you have a perfect recall.';
  } else if (top === 0 && middle === 0 && bottom === 0) {
    document.getElementById('results').innerHTML =
      'Results are not in accordance with Serial Position Effect as none of the items were recalled.';
  } else if (top + bottom >= middle) {
    document.getElementById('results').innerHTML =
      'Results are in accordance with Serial Position Effect as more items from top and bottom were recalled.';
  } else {
    document.getElementById('results').innerHTML =
      'Results are not in accordance with Serial Position effect as more items from middle were recalled.';
  }
  document.getElementById('recall-val').innerHTML = `${(
    ((top + middle + bottom) / userAnimals.length) *
    100
  ).toFixed(2)}%`;
  document.getElementById('page-3').style.display = 'none';
  document.getElementById('page-4').style.display = 'block';
  console.log(top, middle, bottom);
}
