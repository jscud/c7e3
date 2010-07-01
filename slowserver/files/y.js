window['y'] = true;

function renderY(nodeId) {
  document.getElementById(nodeId).innerHTML = 'From start to y loaded: ' + (new Date().getTime() - startTime);
}
