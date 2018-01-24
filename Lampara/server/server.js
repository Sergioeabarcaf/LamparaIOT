var express = require('express'),
	app = express(),
	server = require('http').createServer(app),
  mqtt = require('mqtt');

//Puerto donde corre el sistema
server.listen(8080);

//Ruteo a las paginas
app.use(express.static(__dirname + '/assets'));
app.get('/', function(req, res) {
	res.sendFile(__dirname + '/views/index.html');
});
