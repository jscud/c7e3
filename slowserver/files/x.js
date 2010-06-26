window['x'] = true;

function renderTime(nodeId) {
  document.getElementById(nodeId).innerHTML = new Date().getTime();
}
