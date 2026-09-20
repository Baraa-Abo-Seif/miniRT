Object Coordinates


الفكرة هي تحويل:

P_world

إلى إحداثيات بالنسبة إلى الـObject.

مثلاً Sphere مركزها:

C = (10, 0, 0)

والنقطة:

P_world = (12, 1, -2)

بالنسبة إلى مركز Sphere:

P_object = P_world - C

فنحصل على:

P_object = (2, 1, -2)

الآن الـPattern يرى:

(2,1,-2)

بدلاً من:

(12,1,-2)

وهذا يعني أن Pattern أصبح مرتبطًا بالـObject.