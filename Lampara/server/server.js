var express = require('express'),
	app = express(),
	server = require('http').createServer(app),
	io = require("socket.io").listen(server),
  mqtt = require('mqtt'),
	client = mqtt.connect({host:'192.168.1.166',port:1883});


//*****************
//*****************
//SERVIDOR WEB
//*****************
//*****************

//Puerto donde corre el sistema
server.listen(8080);

//Ruteo a las paginas
app.use(express.static(__dirname + '/assets'));
app.get('/', function(req, res) {
	res.sendFile(__dirname + '/views/index.html');
});


//*****************
//*****************
//COMUNICACION MQTT
//*****************
//*****************
client.on('connect', function() {
	client.subscribe('stateLuz');
});

client.on('message', function(topic, message){
	if (topic == "stateLuz"){
		console.log(message);
	}

});

//*****************
//*****************
//COMUNICACION SOCKET
//*****************
//*****************
io.sockets.on('connection', function(socket) {
	socket.on('sendCom', function(data){
		client.publish('luz',data.value);
		console.log("se envio por mqtt, el dato: " + data.value);
	})
});
