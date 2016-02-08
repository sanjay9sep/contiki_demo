#include "contiki.h"
#include <stdlib.h>

#include <string.h>
#include "rest-engine.h"
static void res_post_put_handler(void *request, void *response, uint8_t *buffer, uint16_t preferred_size, int32_t *offset);
static void res_get_handler(void *request, void *response, uint8_t *buffer, uint16_t preferred_size, int32_t *offset);


RESOURCE(res_example2,
         "title=\"LEDs: ?color=r|g|b, POST/PUT mode=on|off\";rt=\"Control\"",
         res_get_handler,
         res_post_put_handler,
         res_post_put_handler,
         NULL);
static int status = 0;
static void
res_get_handler(void *request, void *response, uint8_t *buffer, uint16_t preferred_size, int32_t *offset)
{
	/*const uint8_t *chunk;*/





		/* coap_get_payload(request, &chunk);*/

		/*length = atoi(chunk);*/
		if (status == 1){
			const char *msg = "light is on";

			/*coap_set_payload(response,(char*)msg,strlen(msg));*/
			REST.set_response_payload(response, msg, strlen(msg));
		}
		else if (status == 0){
			const char *msg = "light is off";
			/*coap_set_payload(response,(char*)msg,strlen(msg));*/
			REST.set_response_payload(response, msg, strlen(msg));

		}
		else {
			const char *msg = "no status";
		   /* coap_set_payload(response,(char*)msg,strlen(msg));*/
			REST.set_response_payload(response, msg, strlen(msg));
		}

}





static void
res_post_put_handler(void *request, void *response, uint8_t *buffer, uint16_t preferred_size, int32_t *offset)
{
	const uint8_t *chunk;



	  /*REST.get_post_variable(request,"chunk",&chunk);*/
	/* coap_get_payload(request, &chunk);*/
	REST.get_request_payload (request,&chunk);

	status = atoi(chunk);
	printf ("%s \n",chunk);
	 if (status == 1){
		 printf("light is on \n");

	 }
	 else if (status == 0) {
		 printf("light is off \n");
	 }
	 else {
		 printf("no status \n");
	 }

}



