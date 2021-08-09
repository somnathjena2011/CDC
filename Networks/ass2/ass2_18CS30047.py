#Kindly install geoip2 by command: pip install geoip2
#Kindly put the mmdb file in the same directory and rename it GeoLite2-Country.mmdb
#xml file obtained by applying filter http.request
#and exporting packet dissections as PDML XML in wireshark
#Better if packets exported as PDML XML
#Link to download mmdb database: https://dev.maxmind.com/geoip/geoip2/geolite2/
import sys
import os
import xml.etree.ElementTree as et 
import geoip2.database
import csv
#function to produce the csv output
#fields of http packets used to determine users who used Internet.org proxy:
#Via: Internet.org\r\n indicates that the request has been forwarded via a proxy server
#X-Fowarded-For indicates the original ip address whose request has been forwarded
def produceCSV(httpTree):
	root = httpTree.getroot()
	httpProtos = root.findall("./packet/proto[@name='http']")		#find all http request Packets
	print("Number of http request packets = ",len(httpProtos));
	ipSet = set()			#set of all unique ips
	countryCount = dict()	#dictionary of country name and corresponding users

	for packet in httpProtos:		#iterate over all http requests
		viaProxy = packet.findall("field[@showname='Via: Internet.org\\r\\n']")	#find field with showname Via: Internet.org(proxy server)
		ipArray = packet.findall("field[@name='http.x_forwarded_for']")			#find field with ip address in X-forwarded-for
		if len(ipArray)>0 and viaProxy:			#if ip present and viaProxy is not None
			ip = ipArray[0].attrib.get("show")	#ip is basically the single element in ipArray
			ipSet.add(ip)						#add ip to the ipSet
	print("Number of unique ip that accessed via proxy server = ",len(ipSet));

	for ip in ipSet:				#iterate over the unique ip addresses
		response = None
		with geoip2.database.Reader('GeoLite2-Country.mmdb') as reader:
			response = reader.country(ip)		#for each unique ip find response using geoip2 and mmdb database
		try:
			country = response.country.name 	#get country name
			countryCount[country]=countryCount.get(country,0)+1 #increase count of country name in countryCount dictioinary
		except Error:
			print(Error)

	countryNameCount = [] 	#list to store country:users as individual dictionaries
	for key, value in countryCount.items():
		countryNameCount.append({"Country":key,"Users":value})

	csv_file = "data.csv"
	try:
		with open(csv_file,"w") as csvfile:
			writer = csv.DictWriter(csvfile, fieldnames=["Country","Users"])
			for data in countryNameCount:
				writer.writerow(data) #write each dictionary in countryNameCount into csv file
	except IOError:
		print("IO Error")
#xml tree structure:
#root 		     : pdml
#pdml->children  : packets
#packet->children: protos(gen-info,frame,eth,ip,tcp,http)
#protos->children: fields
http_requests = et.parse(sys.argv[1])#parse the xml document in form of a rooted tree
produceCSV(http_requests)            #produce the output CSV file from the tree http_requests