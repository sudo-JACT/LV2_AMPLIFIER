#include "lv2.h"


/*AMP STRUCT*/
typedef struct {
  
  float* audio_in_ptr;
  float* audio_out_ptr;
  float* amp_ptr;

}MyAmp;


/*CORE METHODS*/
LV2_Handle instantiate(const struct LV2_Descriptor *descriptor, double sample_rate, const char *bundle_path, const LV2_Feature *const *feature) {

  MyAmp* m = (MyAmp*)calloc(1, sizeof(MyAmp));

  return m;

}

void connect_port(LV2_Handle instance, uint32_t port, void *data_location) {

  MyAmp* m = (MyAmp*) instance;

  if (!m) {

    return;

  }

}

void activate(LV2_Handle instance) {

  /*fsfdsfsfds*/

}

void run(LV2_Handle instance, uint32_t sample_count) {

  /*fsdfsfsfsdfdsfdsf*/

}

void deactivate(LV2_Handle instance) {

  /*dfgdgdgdgd*/

}

void cleanup(LV2_Handle instance) {

  /*sfsdsfsfsf*/


}

const void* extension_data(const char *uri) {

  /*sfsfsdfsf*/

}


/*INTERFACE*/
LV2_SYMBOL_EXPORT const LV2_Descriptor* 	lv2_descriptor (uint32_t index) {


  /*ssdfdsfdsfsdfdsf*/


}
