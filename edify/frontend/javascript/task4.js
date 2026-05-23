function clearColors() {
    document.getElementById("circle1").style.backgroundColor = "#ddd";
    document.getElementById("circle2").style.backgroundColor = "#ddd";
    document.getElementById("circle3").style.backgroundColor = "#ddd";
  }

  function changeColor(color) {
    clearColors();
    switch (color) {
      case "red":
        document.getElementById("circle1").style.backgroundColor = "red";
        break;
      case "orange":
        document.getElementById("circle2").style.backgroundColor = "orange";
        break;
      case "green":
        document.getElementById("circle3").style.backgroundColor = "green";
        break;
      default:
        console.log("Unknown color");
    }
  }