#!/usr/bin/env python3
from http.server import HTTPServer, BaseHTTPRequestHandler
 
HOST = "127.0.0.1"
PORT = 80
 
class RequestHandler(BaseHTTPRequestHandler):
    def do_GET(self):
        self.send_response(200)
        self.send_header('Content-Type', 'text/html')
        self.end_headers()
        self.wfile.write('<ss>success</ss>'.encode())
 
def run_server():
    server = HTTPServer((HOST, PORT), RequestHandler)
    server.serve_forever()
 
if __name__ == '__main__':
    # redirect www.sweetscape.com to 127.0.0.1 in hosts
    run_server()
