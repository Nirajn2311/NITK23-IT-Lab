const form = document.getElementById('form1');
const title = document.getElementById('title');
const id = document.getElementById('treeid');
const name = document.getElementById('treename');
const type = document.getElementById('treetype');
const length = document.getElementById('treelength');
const girth = document.getElementById('treegirth');
const datetime = document.getElementById('datetime');
const gps_latitude = document.getElementById('gpslatitude');
const gps_longitude = document.getElementById('gpslongitude');

form.addEventListener('submit', e => {
  e.preventDefault();

  form.style.display = 'none';
  title.style.display = 'none';
  document.getElementById('heading').innerHTML = 'Recorded Values';
  document.getElementById('Name').innerHTML = '<b>Tree Name</b>: ' + name.value;
  document.getElementById('ID').innerHTML = '<b>Tree ID</b>: ' + id.value;
  document.getElementById('type').innerHTML = '<b>Tree Type</b>: ' + type.value;
  document.getElementById('Length').innerHTML =
    '<b>Tree Length</b>: ' + length.value;
  document.getElementById('Girth').innerHTML =
    '<b>Tree Girth</b>: ' + girth.value;
  document.getElementById('date').innerHTML =
    '<b>Observation date and time</b>: ' +
    new Date(datetime.value).toLocaleString();
  document.getElementById('gpslat').innerHTML =
    '<b>GPS Latitude</b>: ' + gps_latitude.value;
  document.getElementById('gpslong').innerHTML =
    '<b>GPS Longitude</b>: ' + gps_longitude.value;
});
