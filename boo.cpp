#include "foo.h"

#ifdef __cplusplus
extern "C" {
#endif
  /*
   * Class:     foo
   * Method:    sayHello
   * Signature: (Lfoo/FooClass;)V
   */
  JNIEXPORT void JNICALL Java_foo_sayHello(JNIEnv* env, jobject thisObject, jobject fooObject) {
    jclass fooObjectFlass = env->GetObjectClass(fooObject);
    jfieldID a = env->GetFieldID(fooObjectFlass, "a", "I");
    jfieldID b = env->GetFieldID(fooObjectFlass, "b", "I");
    env->SetIntField(fooObject, a, (jint)10);
    env->SetIntField(fooObject, b, (jint)20);
  }

#ifdef __cplusplus
}
#endif
