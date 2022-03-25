const express = require('express');
const routes = require('./controllers/routes');

const app = express();

app.set('view engine', 'ejs');

app.use(express.static('public'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));

app.use(routes);

app.use((req, res) => {
    res.status(404).render('404');
});

app.listen(3000, _ => console.log('Server running on port 3000'));
