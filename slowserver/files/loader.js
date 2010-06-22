// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


// ==ClosureCompiler==
// @compilation_level ADVANCED_OPTIMIZATIONS
// @output_file_name default.js
// ==/ClosureCompiler==


window['loader'] = window['loader'] || {};
loader.waiting = [];


loader.loadScript = function(url) {
  window.setTimeout(function() {
    if (document.body) {
      var newScript = document.createElement('script');
      newScript.type = 'text/javascript';
      newScript.src = url;
      document.body.appendChild(newScript);
    } else {
      document.write('<scr' + 'ipt type="text/javascript" src="' + url + '"><\/scr' + 'ipt>');
    }
  }, 1);
};


loader.whenReady = function(testFunction, callback) {
  if (testFunction()) {
    callback();
  } else {
    loader.waiting.push([testFunction, callback]);
    window.setTimeout(loader.checkWaiting, 200);
  }
};


loader.checkWaiting = function() {
  var oldWaiting = loader.waiting;
  var numWaiting = oldWaiting.length;
  loader.waiting = [];
  for (var i = 0; i < numWaiting; i++) {
    if (oldWaiting[i][0]()) {
      oldWaiting[i][1]();
    } else {
      loader.waiting.push(oldWaiting[i]);
    }
  }

  if (loader.waiting.length > 0) {
    window.setTimeout(loader.checkWaiting, 200);
  }
};


loader.whenNodePresent = function(nodeId, callback) {
  loader.whenReady(function () {
    return document.getElementById(nodeId);
  }, callback);
};


window['loader'] = loader;
window['loader']['loadScript'] = loader.loadScript;
window['loader']['whenReady'] = loader.whenReady;
window['loader']['whenNodePresent'] = loader.whenNodePresent;
