import sys
import os
import xml.etree.ElementTree as et
import geoip2.database
import csv

def produceCSV(httpTree):
    root = httpTree.getroot()
    httpProtos = root.findall("./packet/proto[@name='http']")
    print("No of http request packets = ",len(httpProtos))
    ipSet = set()
    countryCount = dict()

    for packet in httpProtos:
        viaProxy = packet.findall("field[@showname='Via: Internet.org\\r\\n']")
        ipArray  = packet.findall("field[@name='http.x_forwarded_for']")
        if len(ipArray)>0 and viaProxy:
            ip = ipArray[0].attrib.get("show")
            ipSet.add(ip)
    print("No of unique IP that accessed via proxy = ",len(ipSet))

    for ip in ipSet:
        response = None
        with geoip2.database.Reader('GeoLite2-Country.mmdb') as reader:
            response = reader.country(ip)
        try:
            country = response.country.name
            countryCount[country]=countryCount.get(country,0)+1
        except Error:
            print(Error)

    countryNameCount = []
    for key, value in countryCount.items():
        countryNameCount.append({"Country":key,"Users":value})

    csv_file = 'data.csv'
    try:
        with open(csv_file,"w") as csvfile:
            writer = csv.DictWriter(csvfile,fieldnames=['Country','Users'])
            for data in countryNameCount:
                writer.writerow(data)
    except IOError:
        print("IO Error")

http_requests = et.parse(sys.argv[1])
produceCSV(http_requests)
