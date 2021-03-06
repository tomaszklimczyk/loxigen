:: # Copyright 2013, Big Switch Networks, Inc.
:: #
:: # LoxiGen is licensed under the Eclipse Public License, version 1.0 (EPL), with
:: # the following special exception:
:: #
:: # LOXI Exception
:: #
:: # As a special exception to the terms of the EPL, you may distribute libraries
:: # generated by LoxiGen (LoxiGen Libraries) under the terms of your choice, provided
:: # that copyright and licensing notices generated by LoxiGen are not altered or removed
:: # from the LoxiGen Libraries and the notice provided below is (i) included in
:: # the LoxiGen Libraries, if distributed in source code form and (ii) included in any
:: # documentation for the LoxiGen Libraries, if distributed in binary form.
:: #
:: # Notice: "Copyright 2013, Big Switch Networks, Inc. This library was generated by the LoxiGen Compiler."
:: #
:: # You may not use this file except in compliance with the EPL or LOXI Exception. You may obtain
:: # a copy of the EPL at:
:: #
:: # http://www.eclipse.org/legal/epl-v10.html
:: #
:: # Unless required by applicable law or agreed to in writing, software
:: # distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
:: # WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
:: # EPL for the specific language governing permissions and limitations
:: # under the EPL.
::
static void
${data.class_name}_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
:: for ms, versions in data.versioned_type_members:
:: for version in versions:
    case ${version.constant_version(prefix='OF_VERSION_')}:
:: #endfor
:: for m in ms:
:: if m.length == 1:
        *(uint8_t *)(buf + ${m.offset}) = ${m.value}; /* ${m.name} */
:: elif m.length == 2:
        *(uint16_t *)(buf + ${m.offset}) = htobe16(${m.value}); /* ${m.name} */
:: elif m.length == 4:
        *(uint32_t *)(buf + ${m.offset}) = htobe32(${m.value}); /* ${m.name} */
:: else:
:: raise("unsupported push_wire_types length %d" % m.length)
:: #endif
:: #endfor
        break;
:: #endfor
    default:
        UNREACHABLE();
    }
}
