function switchFunction(inp) {
    if (inp=="1") {
      console.log("entro a encender");
      var x = document.getElementById("onB");
      x.innerHTML = "disable";
      var y = document.getElementById("offB");
      y.innerHTML = "Apagar";
      socket.emit('sendCom',{
        value:inp
      });
      console.log("se envia dato por socket a controlador");
    }
    if (inp=="0") {
      console.log("entro a apagar");
      var x = document.getElementById("offB");
      x.innerHTML = "disable";
      var y = document.getElementById("onB");
      y.innerHTML = "Encender";
      socket.emit('sendCom',{
        value:inp
      });
      console.log("se envia dato por socket a controlador");
    }
}
