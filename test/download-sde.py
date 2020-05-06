#!/usr/bin/python3

import requests, sys
from urllib.parse import urljoin
from io import StringIO
from lxml import etree

session = requests.Session()

dl_list_url = 'https://software.intel.com/en-us/articles/pre-release-license-agreement-for-intel-software-development-emulator-accept-end-user-license-agreement-and-download'
dl_list = None
dl_list = session.get(dl_list_url).text
dl_list_data = etree.parse(StringIO(dl_list), etree.HTMLParser())

license_url = urljoin(dl_list_url, str(dl_list_data.xpath('(//a[text()="Download Intel® SDE for Linux*"])[1]/@href')[0]))
license = None
license = session.get(license_url).text
license_data = etree.parse(StringIO(license), etree.HTMLParser())

dl_page_url = urljoin(license_url, license_data.xpath('//form[@id="intel-licensed-dls-step-1"]/@action')[0])
form = { }
for input in license_data.xpath('//form[@id="intel-licensed-dls-step-1"]//input'):
    form[input.xpath('@name')[0]] = input.xpath('@value')[0]
dl_page = None
dl_page = session.post(dl_page_url, data=form).text
dl_page_data = etree.parse(StringIO(dl_page), etree.HTMLParser())

archive_url = dl_page_data.xpath('(//a[contains(@href, "-lin.tar.bz2")]/@href)[1]')[0]

with session.get(archive_url, stream=True) as r:
    size = int(r.headers['Content-Length'])
    bytes_read = 0
    with open(sys.argv[1], "wb") as fp:
        for chunk in r.iter_content(chunk_size=(1024 * 1024)):
            bytes_read += len(chunk)
            print("%3.1f%%" % ((bytes_read / size) * 100))
            fp.write(chunk)
