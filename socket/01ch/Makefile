hserver:hserver.o
	g++ -o hserver hserver.o

hclient:hclient.o
	g++ -o hclient hclient.o

hserver.o:hello_server.c
	g++ -c hello_server.c -o hserver.o

hclient.o:hello_client.c
	g++ -c hello_client.c -o hclient.o

clean:
	rm *.o hserver hclient