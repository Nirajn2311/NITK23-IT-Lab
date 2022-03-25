const container = document.querySelector('.container');
const message = document.querySelector('.message');
const button = document.querySelector('button');
const gameArea = document.querySelector('.gameArea');
const results = document.querySelector('.results');
const directions = document.querySelector('.directions');
const infoTableBody = document.getElementById('info-table-body');
const infoGraph = document.getElementById('info-graph');

let inPlay = false;
let playArea = {};
// Change the below value to change the number of circles
let circleCount = 30;
let count = 0;
let mouseX = 0;
let mouseY = 0;
let diameter = [];
let distance = [];
let time = [];
let graph;

function showMessage(notification) {
  message.innerHTML = `<h3>${notification}</h3>`;
}

function showBox() {
  playArea.timer = setTimeout(myBox, random(4000));
}

function calcuDist(x1, y1, x2, y2) {
  let xDist = x2 - x1;
  let yDist = y2 - y1;
  return Math.sqrt(Math.pow(xDist, 2) + Math.pow(yDist, 2));
}

function myBox() {
  let element = document.createElement('div');
  var num = Math.floor(Math.random() * (100 - 10)) + 10;
  diameter.push(num);
  element.classList.add('box');
  element.style.top = random(setTopMargin()) + 'px';
  element.style.left = random(setLeftMargin()) + 'px';
  element.style.backgroundColor = '#FF0000';
  element.style.height = num + 'px';
  element.style.width = num + 'px';
  element.start = new Date().getTime();
  element.addEventListener('click', hit);
  gameArea.appendChild(element);
}

function setTopMargin() {
  let maxHeight = gameArea.clientHeight;
  if (maxHeight <= 100) {
    maxHeight = maxHeight + 200;
  } else {
    maxHeight = maxHeight - 200;
  }
  return maxHeight;
}

function setLeftMargin() {
  let maxWidth = gameArea.clientWidth;
  if (maxWidth <= 100) {
    maxWidth = maxWidth + 200;
  } else {
    maxWidth = maxWidth - 200;
  }

  return maxWidth;
}

function hit(e) {
  let start = e.target.start;
  let end = new Date().getTime();
  let duration = (end - start) / 1000;

  clearTimeout(playArea.timer);
  time.push(duration);

  let currRad = diameter[diameter.length - 1];
  let currDist = calcuDist(
    mouseX,
    mouseY,
    e.target.offsetLeft + currRad,
    e.target.offsetTop + currRad
  );
  distance.push(currDist);
  mouseX = e.clientX;
  mouseY = e.clientY;

  gameArea.children[0].remove();
  playArea.timer = setTimeout(myBox, random(4000));
  count++;
  if (count === circleCount) {
    results.style.display = 'block';
    showMessage('Congratulations!!');
    for (let i = 0; i < distance.length; i++) {
      let row = document.createElement('tr');
      let cell1 = document.createElement('th');
      let cell2 = document.createElement('td');
      let cell3 = document.createElement('td');
      let cell4 = document.createElement('td');
      cell1.innerHTML = i + 1;
      cell1.scope = 'row';
      cell2.innerHTML = time[i];
      cell3.innerHTML = distance[i].toFixed(2);
      cell4.innerHTML = diameter[i];
      row.appendChild(cell1);
      row.appendChild(cell2);
      row.appendChild(cell3);
      row.appendChild(cell4);
      infoTableBody.appendChild(row);
    }
    let dataset = [];
    diameter.forEach((d, i) => {
      dataset.push({
        x: d,
        y: time[i],
      });
    });
    graph = new Chart(infoGraph, {
      type: 'scatter',
      data: {
        datasets: [
          {
            label: 'Diameter vs Time',
            data: dataset,
            backgroundColor: 'rgb(255, 99, 132)',
          },
        ],
      },
    });
    container.style.height = 'auto';
    resetGame();
    time = [];
    diameter = [];
    distance = [];
  } else {
    showMessage(`Circle: ${count + 1}/30`);
  }
}

function random(number) {
  let tempVal = Math.floor(Math.random() * number);
  return tempVal;
}

function resetGame() {
  clearTimeout(playArea.timer);
  inPlay = false;
  button.style.display = 'block';
}

button.addEventListener('click', function () {
  inPlay = true;
  button.style.display = 'none';
  directions.style.display = 'none';
  results.style.display = 'none';
  infoTableBody.innerHTML = '';
  graph ? graph.destroy() : null;
  count = 0;
  showMessage('Circle: 1/30');
  showBox();
  container.style.height = '600px';
});
