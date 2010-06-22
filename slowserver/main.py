#!/usr/bin/env python
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import os
import time
from google.appengine.ext import webapp
from google.appengine.ext.webapp import util


def FilePath(path):
  """The requested path into a local file path."""

  return os.path.join(os.path.dirname(__file__), 'files', path[1:])


class SleepyRenderer(webapp.RequestHandler):
  """Serves the requested page with a client configured delay.

  Delay is given as a URL parameter in hundredths of a second to delay.
  For example, 200 means wait 2 seconds before responding.

  Example request:
  http://localhost:8080/hi.html?delay=300&contenttype=text/html
  """

  def get(self):
    path = self.request.path
    delay = self.request.get('delay')
    content_type = self.request.get('contenttype') or 'text/html'
    if delay:
      time.sleep(int(delay)/100)
    http_status = 200
    requested_file = None

    try:
      requested_file = open(FilePath(path))
      self.response.out.write(requested_file.read())
      requested_file.close()
    except IOError:
      http_status = 404

    self.response.set_status(http_status)
    self.response.headers['Content-Type'] = content_type


def main():
    application = webapp.WSGIApplication([('/.*', SleepyRenderer)],
                                         debug=True)
    util.run_wsgi_app(application)


if __name__ == '__main__':
    main()
