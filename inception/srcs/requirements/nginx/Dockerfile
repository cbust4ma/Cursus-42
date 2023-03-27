#This is a sample Image 
FROM debian:buster
MAINTAINER cbustama@student.42urduliz.com 
WORKDIR /home/cbustama
RUN apt update\ 
	&& apt -y install nginx\ 
	&& apt clean\
	&& rm -rf /var/lib/apt/lists/* 
COPY "/conf/default.conf" /etc/nginx/conf.d
COPY "/conf/nginx.pem" /etc/nginx/
EXPOSE 443
CMD ["nginx", "-g", "daemon off;"] 
