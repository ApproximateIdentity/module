#include <Python.h>
#include <structmember.h>

#include <stdio.h>


static PyObject* KError;

typedef struct {
    PyObject_HEAD
    int i;
} kobject;

static void
kdealloc(kobject* self) {
    printf("calling kdealloc\n");
    self->i = -1;
    self->ob_type->tp_free((PyObject*)self);
}

static int
kinit(kobject* self, PyObject* args, PyObject* kwds) {
    printf("calling kinit\n");
    int i = -1;
    if (!PyArg_ParseTuple(args, "i", &i)) {
        return -1;
    }
    if (i < 0) {
        PyErr_SetString(KError, "Must pass in non-negative int!");
        return -1;
    }
    self->i = i;
    return 0;
}

static PyObject*
kid(kobject* self) {
    return PyInt_FromLong(self->i);
}

static PyMethodDef KlassMethods[] = {
    {"id", kid, METH_NOARGS, "Get id of class."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

static PyTypeObject KlassType = {
    PyObject_HEAD_INIT(NULL)
    0,                         /*ob_size*/
    "module.klass",             /*tp_name*/
    sizeof(kobject), /*tp_basicsize*/
    0,                         /*tp_itemsize*/
    (destructor)kdealloc,                         /*tp_dealloc*/
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
    (initproc)kinit,      /* tp_init */
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

    KError = PyErr_NewException("module.KError", NULL, NULL);
    Py_INCREF(KError);
    PyModule_AddObject(m, "KError", KError);
}
