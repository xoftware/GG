echo '{ "content" : "192.168.44.130:9000" }' > bin/web.json

node bin/web.js		\
 --config ./web.json 	&

node bin/content.js
