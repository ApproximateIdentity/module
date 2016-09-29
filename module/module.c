#include <Python.h>
#include <structmember.h>


typedef struct {
    PyObject_HEAD
} kobject;

static PyMethodDef KlassMethods[] = {
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

static PyTypeObject KlassType = {
    PyObject_HEAD_INIT(NULL)
    0,                         /*ob_size*/
    "module.klass",             /*tp_name*/
    sizeof(kobject), /*tp_basicsize*/
    0,                         /*tp_itemsize*/
    0,                         /*tp_dealloc*/
    0,                         /*tp_print*/
    0,                         /*tp_getattr*/
    0,                         /*tp_setattr*/
    0,                         /*tp_compare*/
    0,                         /*tp_repr*/
    0,                         /*tp_as_number*/
    0,                         /*tp_as_sequence*/
    0,                         /*tp_as_mapping*/
    0,                         /*tp_hash */
    0,                         /*tp_call*/
    0,                         /*tp_str*/
    0,                         /*tp_getattro*/
    0,                         /*tp_setattro*/
    0,                         /*tp_as_buffer*/
    Py_TPFLAGS_DEFAULT,        /*tp_flags*/
    "Klass with a K!",           /* tp_doc */
    0,                     /* tp_traverse */
    0,                     /* tp_clear */
    0,                     /* tp_richcompare */
    0,                     /* tp_weaklistoffset */
    0,                     /* tp_iter */
    0,                     /* tp_iternext */
    KlassMethods,             /* tp_methods */
    0,             /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    0,      /* tp_init */
    0,                         /* tp_alloc */
    0,                 /* tp_new */
};

static PyMethodDef ModuleMethods[] = {
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

PyMODINIT_FUNC
initmodule(void)
{
    PyObject *m;
    m = Py_InitModule("module", ModuleMethods);
    if (m == NULL) {
        return;
    }

    KlassType.tp_new = PyType_GenericNew;
    if (PyType_Ready(&KlassType) < 0) {
        return;
    }
    Py_INCREF(&KlassType);
    PyModule_AddObject(m, "Klass", (PyObject *)&KlassType);
}
