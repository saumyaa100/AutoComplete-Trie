const express = require('express');
const path = require('path');
const autocompleteRoute = require('./routes/autocomplete');

const app = express();
const port = 3000;

app.use(express.static(path.join(__dirname, '../public')));
app.use('/', autocompleteRoute);

module.exports = app;
