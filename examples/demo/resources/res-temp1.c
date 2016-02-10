#include "contiki.h"

#if PLATFORM_HAS_TEMPERATURE

#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "rest-engine.h"
#include "dev/temperature-sensor.h"
static void res_get_handler(void *request, void *response, uint8_t *buffer, uint16_t preferred_size, int32_t *offset);



RESOURCE(res_temp1,
         "title=\"Temperature\";rt=\"Temperature\";obs",
         res_get_handler,
         NULL,
         NULL,
         NULL);
static void
res_get_handler(void *request, void *response, uint8_t *buffer, uint16_t preferred_size, int32_t *offset)
{
	int temperature = temperature_sensor.value(0);

	  unsigned int accept = -1;
	  REST.get_header_accept(request, &accept);

	  if(accept == -1 || accept == REST.type.TEXT_PLAIN) {
	    REST.set_header_content_type(response, REST.type.TEXT_PLAIN);
	    snprintf((char *)buffer, REST_MAX_CHUNK_SIZE, "%d", temperature);

}


