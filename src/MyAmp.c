#include <lv2.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

/*AMP STRUCT*/
typedef struct {
  
  float* audio_in_ptr;
  float* audio_out_ptr;
  float* amp_ptr;

}MyAmp;


/*CORE METHODS*/
static LV2_Handle instantiate(const struct LV2_Descriptor *descriptor, double sample_rate, const char *bundle_path, const LV2_Feature *const *feature) {

  MyAmp* m = (MyAmp*)calloc(1, sizeof(MyAmp));

  return m;

}

static void connect_port(LV2_Handle instance, uint32_t port, void *data_location) {

  MyAmp* m = (MyAmp*) instance;

  if (!m) {

    return;

  }

  switch (port) {

    case 0:
  
      m->audio_in_ptr = (float*) data_location;

      break;

    case 1:

      m->audio_out_ptr = (float*) data_location;
      
      break;

    case 2:

      m->amp_ptr = (float*) data_location;

      break;

    default:
      
      break;
  }

}

static void activate(LV2_Handle instance) {

  /*nothing here*/

}

static void run(LV2_Handle instance, uint32_t sample_count) {

  MyAmp* m = (MyAmp*) instance;

  if (!m || !m->audio_in_ptr || !m->audio_out_ptr || !m->amp_ptr) {

    return;
    
  }

  for (uint32_t i=0; i < sample_count; i++) {

    m->audio_out_ptr[i] = m->audio_in_ptr[i] * *(m->amp_ptr);
    
  }

}

static void deactivate(LV2_Handle instance) {

  /*nothing here*/

}

static void cleanup(LV2_Handle instance) {

  MyAmp* m = (MyAmp*) instance;

  if (!m) {

    return;
    
  }

  free(m);

}

static const void* extension_data(const char *uri) {

  return NULL;

}


/*DESCRIPTOR*/

static LV2_Descriptor const descriptor = {

  "https://github.com/sudo-JACT/LV2_AMPLIFIER.git",
  instantiate,
  connect_port,
  activate /* or NULL */,
  run,
  deactivate /* or NULL*/,
  cleanup,
  extension_data /* or NULL */

};

/*INTERFACE*/
LV2_SYMBOL_EXPORT const LV2_Descriptor* 	lv2_descriptor (uint32_t index) {


  if (index == 0) {

    return &descriptor;
    
  }else {
    
    return NULL;

  }


}
