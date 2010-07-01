window['x'] = true;

function renderX(nodeId) {
  document.getElementById(nodeId).innerHTML = 'From start to x loaded: ' + (new Date().getTime() - startTime);
}
