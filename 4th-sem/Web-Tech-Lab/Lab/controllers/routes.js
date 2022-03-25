const express = require('express');
const router = express.Router();
const fs = require('fs');
const crypto = require('crypto');

router.get('/', (req, res) => {
    res.render('home');
});

router.route('/login')
    .get((req, res) => {
        res.render('login');
    })
    .post((req, res) => {
        let rawdata = fs.readFileSync('./models/users.json');
        let users = JSON.parse(rawdata);

        const email = req.body.email;
        const pwd = req.body.password;

        for (let [id, user] of Object.entries(users)) {
            if (user.email === email && user.pwd === pwd) {
                return res.redirect(`/profile/${id}`);
            }
        }

        res.render('login', { success: false });
    });

router.route('/signup')
    .get((req, res) => {
        res.render('signup');
    })
    .post((req, res) => {
        let rawdata = fs.readFileSync('./models/users.json');
        let users = JSON.parse(rawdata);

        const id = crypto.randomBytes(8).toString("hex");
        const email = req.body.email;
        const pwd = req.body.password;

        for (let [id, user] of Object.entries(users)) {
            if (user.email === email) {
                return res.render('signup', { success: false });
            }
        }

        users[id] = { email, pwd };
        fs.writeFileSync('./models/users.json', JSON.stringify(users));
        res.redirect(`/profile/${id}`);
    });

router.route("/profile/:id")
    .get((req, res) => {
        let rawdata = fs.readFileSync('./models/users.json');
        let users = JSON.parse(rawdata);
        let id = req.params.id;

        let user = users[id];

        res.render('user', { data: user });
    });

router.route("/form")
    .post((req, res) => {
        let data = req.body;
        res.render('form', { data });
    });


module.exports = router;