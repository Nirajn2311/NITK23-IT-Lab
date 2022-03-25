const input = document.getElementById('input');
const numeric = document.getElementById('numeric'); // Type 1
const alphaNumeric = document.getElementById('alpha-numeric'); // Type 2
const capsLockBtn = document.getElementById('caps-lock-btn');

const digits = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9'];
const rowQWER = ['q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'];
const rowASDF = ['a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'];
const rowZXCV = ['z', 'x', 'c', 'v', 'b', 'n', 'm'];
let shuffledDigits = digits.sort(() => 0.5 - Math.random());
let shuffledQWER = splitAndShuffle(rowQWER);
let shuffledASDF = splitAndShuffle(rowASDF);
let shuffledZXCV = splitAndShuffle(rowZXCV);

document.querySelectorAll('#numeric > div').forEach((div, index) => {
  div.innerHTML = shuffledDigits[index];
  div.addEventListener('click', e => appendInputValue(e.target.innerHTML));
});

document
  .querySelectorAll(
    '#row-numeric div, #row-qwer div, #row-asdf div, #row-zxcv div'
  )
  .forEach(div => {
    div.addEventListener('click', e => {
      appendInputValue(
        e.target.parentElement.style.textTransform === 'uppercase'
          ? e.target.innerHTML.toUpperCase()
          : e.target.innerHTML
      );
    });
  });

document.querySelectorAll('#row-numeric > div').forEach((div, index) => {
  div.innerHTML = shuffledDigits[index];
});

document.querySelectorAll('#row-qwer > div').forEach((div, index) => {
  div.innerHTML = shuffledQWER[index];
});

document.querySelectorAll('#row-asdf > div').forEach((div, index) => {
  div.innerHTML = shuffledASDF[index];
});

document.querySelectorAll('#row-zxcv > div').forEach((div, index) => {
  div.innerHTML = shuffledZXCV[index];
});

function splitAndShuffle(arr) {
  copyArr = [...arr];
  splitArr = copyArr.splice(0, Math.floor((copyArr.length + 1) / 2));
  splitArr = splitArr.sort(() => 0.5 - Math.random());
  copyArr = copyArr.sort(() => 0.5 - Math.random());
  return [...splitArr, ...copyArr];
}

function changeCase() {
  document.querySelectorAll('#row-qwer, #row-asdf, #row-zxcv').forEach(div => {
    if (div.style.textTransform === 'uppercase') {
      div.style.textTransform = 'lowercase';
      capsLockBtn.style.backgroundColor = 'transparent';
    } else {
      div.style.textTransform = 'uppercase';
      capsLockBtn.style.backgroundColor = '#a3a3a3';
    }
  });
}

function appendInputValue(value) {
  input.value += value;
}

function changeKeyboard(type) {
  input.value = '';
  shuffledDigits = digits.sort(() => 0.5 - Math.random());
  if (type === 1) {
    document.querySelectorAll('#numeric > div').forEach((div, index) => {
      div.innerHTML = shuffledDigits[index];
    });

    numeric.style.display = 'grid';
    alphaNumeric.style.display = 'none';
  } else {
    shuffledQWER = splitAndShuffle(rowQWER);
    shuffledASDF = splitAndShuffle(rowASDF);
    shuffledZXCV = splitAndShuffle(rowZXCV);

    document
      .querySelectorAll('#row-qwer, #row-asdf, #row-zxcv')
      .forEach(div => {
        div.style.textTransform = 'lowercase';
      });
    document.querySelectorAll('#row-numeric > div').forEach((div, index) => {
      div.innerHTML = shuffledDigits[index];
    });
    document.querySelectorAll('#row-qwer > div').forEach((div, index) => {
      div.innerHTML = shuffledQWER[index];
    });
    document.querySelectorAll('#row-asdf > div').forEach((div, index) => {
      div.innerHTML = shuffledASDF[index];
    });
    document.querySelectorAll('#row-zxcv > div').forEach((div, index) => {
      div.innerHTML = shuffledZXCV[index];
    });

    capsLockBtn.style.backgroundColor = 'transparent';
    alphaNumeric.style.display = 'grid';
    numeric.style.display = 'none';
  }
}
