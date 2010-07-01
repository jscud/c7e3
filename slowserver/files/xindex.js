window['index'] = {
  'x': '/x.js?delay=200',
  'y': '/y.js?delay=200'
};

function simpleLoad(name) {
  if (document.body) {
    var newScript = document.createElement('script');
    newScript.src = index[name];
    document.body.appendChild(newScript);
  } else {
    document.write('<script src="' + index[name] + '"></script>');
  }
}
