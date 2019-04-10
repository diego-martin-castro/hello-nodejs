// hello.cc using N-API
#include <node_api.h>

namespace demo {

napi_value Method(napi_env env, napi_callback_info args) {
  napi_value greeting;
  napi_status status;

  napi_value obj;
  napi_value obj2;

  status = napi_create_object(env, &obj);
  if (status != napi_ok) return nullptr;

  status = napi_create_object(env, &obj2);
  if (status != napi_ok) return nullptr;

  // Create napi_values for 123 and 456
  napi_value fooValue, barValue;
  status = napi_create_int32(env, 123, &fooValue);
  if (status != napi_ok) return nullptr;
  status = napi_create_int32(env, 456, &barValue);
  if (status != napi_ok) return nullptr;


  // Set the properties
  napi_property_descriptor descriptors2[] = {
    { "foo", NULL, NULL, NULL, NULL, fooValue, napi_default, NULL },
    { "bar", NULL, NULL, NULL, NULL, barValue, napi_default, NULL }
  };
  status = napi_define_properties(env, obj2, sizeof(descriptors2) / sizeof(descriptors2[0]), descriptors2);


  // Set the properties
  napi_property_descriptor descriptors[] = {
    { "foo", NULL, NULL, NULL, NULL, obj2, napi_default, NULL },
    { "bar", NULL, NULL, NULL, NULL, barValue, napi_default, NULL }
  };
  status = napi_define_properties(env, obj, sizeof(descriptors) / sizeof(descriptors[0]), descriptors);

  if (status != napi_ok) return nullptr;

  napi_value result;
  status = napi_get_element(env, obj, 0, &result);
  if (status != napi_ok) return nullptr;
  return obj;
}

napi_value init(napi_env env, napi_value exports) {
  napi_status status;
  napi_value fn;

  status = napi_create_function(env, nullptr, 0, Method, nullptr, &fn);
  if (status != napi_ok) return nullptr;

  status = napi_set_named_property(env, exports, "hello", fn);
  if (status != napi_ok) return nullptr;
  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, init)

}  // namespace demo