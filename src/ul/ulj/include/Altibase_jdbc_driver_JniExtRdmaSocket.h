/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class Altibase_jdbc_driver_JniExtRdmaSocket */

#ifndef _Included_Altibase_jdbc_driver_JniExtRdmaSocket
#define _Included_Altibase_jdbc_driver_JniExtRdmaSocket
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     Altibase_jdbc_driver_JniExtRdmaSocket
 * Method:    load
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_Altibase_jdbc_driver_JniExtRdmaSocket_load
  (JNIEnv *, jclass);

/*
 * Class:     Altibase_jdbc_driver_JniExtRdmaSocket
 * Method:    unload
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_Altibase_jdbc_driver_JniExtRdmaSocket_unload
  (JNIEnv *, jclass);

/*
 * Class:     Altibase_jdbc_driver_JniExtRdmaSocket
 * Method:    rsocket
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_Altibase_jdbc_driver_JniExtRdmaSocket_rsocket
  (JNIEnv *, jclass, jint);

/*
 * Class:     Altibase_jdbc_driver_JniExtRdmaSocket
 * Method:    rbind
 * Signature: (ILjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_Altibase_jdbc_driver_JniExtRdmaSocket_rbind
  (JNIEnv *, jclass, jint, jstring);

/*
 * Class:     Altibase_jdbc_driver_JniExtRdmaSocket
 * Method:    rconnect
 * Signature: (ILjava/lang/String;II)V
 */
JNIEXPORT void JNICALL Java_Altibase_jdbc_driver_JniExtRdmaSocket_rconnect
  (JNIEnv *, jclass, jint, jstring, jint, jint);

/*
 * Class:     Altibase_jdbc_driver_JniExtRdmaSocket
 * Method:    rclose
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_Altibase_jdbc_driver_JniExtRdmaSocket_rclose
  (JNIEnv *, jclass, jint);

/*
 * Class:     Altibase_jdbc_driver_JniExtRdmaSocket
 * Method:    rrecv
 * Signature: (ILjava/nio/ByteBuffer;III)I
 */
JNIEXPORT jint JNICALL Java_Altibase_jdbc_driver_JniExtRdmaSocket_rrecv
  (JNIEnv *, jclass, jint, jobject, jint, jint, jint);

/*
 * Class:     Altibase_jdbc_driver_JniExtRdmaSocket
 * Method:    rsend
 * Signature: (ILjava/nio/ByteBuffer;III)I
 */
JNIEXPORT jint JNICALL Java_Altibase_jdbc_driver_JniExtRdmaSocket_rsend
  (JNIEnv *, jclass, jint, jobject, jint, jint, jint);

/*
 * Class:     Altibase_jdbc_driver_JniExtRdmaSocket
 * Method:    rsetsockopt
 * Signature: (IIII)V
 */
JNIEXPORT void JNICALL Java_Altibase_jdbc_driver_JniExtRdmaSocket_rsetsockopt
  (JNIEnv *, jclass, jint, jint, jint, jint);

/*
 * Class:     Altibase_jdbc_driver_JniExtRdmaSocket
 * Method:    rgetsockopt
 * Signature: (IIII)V
 */
JNIEXPORT void JNICALL Java_Altibase_jdbc_driver_JniExtRdmaSocket_rgetsockopt
  (JNIEnv *, jclass, jint, jint, jint, jint);

#ifdef __cplusplus
}
#endif
#endif
