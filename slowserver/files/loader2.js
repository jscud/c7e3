var loader = loader || {};

loader.waitingNodes = {};
loader.waitingVars = {};
loader.waiting = false;


loader.loadScript = function(url) {
  if (document.body) {
    var newScript = document.createElement('script');
    newScript.type = 'text/javascript';
    newScript.src = url;
    document.body.appendChild(newScript);
  } else {
    document.write('<scr' + 'ipt type="text/javascript" src="' + url + '"></scr' + 'ipt>');
  }
};


loader.whenNodeReady = function(nodeId, callback) {
  if (document.getElementById(nodeId)) {
    callback();
  } else {
    loader.waitingNodes[nodeId] = callback;
    if (!loader.waiting) {
      loader.waiting = true;
      window.setInterval(loader.checkWaiting, 200);
    }
  }
};


loader.whenVariableTrue = function(variable, callback) {
  if (window[variable]) {
    callback();
  } else {
    loader.waitingVars[variable] = callback;
    if (!loader.waiting) {
      loader.waiting = true;
      window.setInterval(loader.checkWaiting, 200);
    }
  }
};


loader.checkWaiting = function() {
  var oldWaiting = loader.waitingNodes;
  var stillWaiting = false;
  loader.waitingNodes = {};
  for (var node in oldWaiting) {
    if (document.getElementById(oldWaiting[node])) {
      oldWaitingNodes[node]();
    } else {
      loader.waitingNodes[node] = oldWaiting[node]
      stillWaiting = true;
    }
  }

  oldWaiting = loader.waitingVars;
  loader.waitingVars = {};
  for (var variable in oldWaiting) {
    if (window[variable]) {
      oldWaiting[variable]();
    } else {
      loader.waitingVars[variable] = oldWaiting[variable]
      stillWaiting = true;
    }
  }

  if (!stillWaiting) {
    window.clearInterval(loader.checkWaiting);
    loader.waiting = true;
  }
};
