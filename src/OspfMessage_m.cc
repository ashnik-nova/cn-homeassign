//
// Generated file, do not edit! Created by opp_msgtool 6.0 from src/OspfMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "OspfMessage_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

Register_Class(OspfPacket)

OspfPacket::OspfPacket(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

OspfPacket::OspfPacket(const OspfPacket& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

OspfPacket::~OspfPacket()
{
}

OspfPacket& OspfPacket::operator=(const OspfPacket& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void OspfPacket::copy(const OspfPacket& other)
{
    this->type = other.type;
    this->sourceId = other.sourceId;
}

void OspfPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->sourceId);
}

void OspfPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->sourceId);
}

int OspfPacket::getType() const
{
    return this->type;
}

void OspfPacket::setType(int type)
{
    this->type = type;
}

int OspfPacket::getSourceId() const
{
    return this->sourceId;
}

void OspfPacket::setSourceId(int sourceId)
{
    this->sourceId = sourceId;
}

class OspfPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_type,
        FIELD_sourceId,
    };
  public:
    OspfPacketDescriptor();
    virtual ~OspfPacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(OspfPacketDescriptor)

OspfPacketDescriptor::OspfPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(OspfPacket)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

OspfPacketDescriptor::~OspfPacketDescriptor()
{
    delete[] propertyNames;
}

bool OspfPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OspfPacket *>(obj)!=nullptr;
}

const char **OspfPacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *OspfPacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int OspfPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int OspfPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_type
        FD_ISEDITABLE,    // FIELD_sourceId
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *OspfPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "type",
        "sourceId",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int OspfPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "type") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "sourceId") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *OspfPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_type
        "int",    // FIELD_sourceId
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **OspfPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OspfPacketDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OspfPacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    OspfPacket *pp = omnetpp::fromAnyPtr<OspfPacket>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void OspfPacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    OspfPacket *pp = omnetpp::fromAnyPtr<OspfPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'OspfPacket'", field);
    }
}

const char *OspfPacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    OspfPacket *pp = omnetpp::fromAnyPtr<OspfPacket>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OspfPacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    OspfPacket *pp = omnetpp::fromAnyPtr<OspfPacket>(object); (void)pp;
    switch (field) {
        case FIELD_type: return long2string(pp->getType());
        case FIELD_sourceId: return long2string(pp->getSourceId());
        default: return "";
    }
}

void OspfPacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    OspfPacket *pp = omnetpp::fromAnyPtr<OspfPacket>(object); (void)pp;
    switch (field) {
        case FIELD_type: pp->setType(string2long(value)); break;
        case FIELD_sourceId: pp->setSourceId(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'OspfPacket'", field);
    }
}

omnetpp::cValue OspfPacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    OspfPacket *pp = omnetpp::fromAnyPtr<OspfPacket>(object); (void)pp;
    switch (field) {
        case FIELD_type: return pp->getType();
        case FIELD_sourceId: return pp->getSourceId();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'OspfPacket' as cValue -- field index out of range?", field);
    }
}

void OspfPacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    OspfPacket *pp = omnetpp::fromAnyPtr<OspfPacket>(object); (void)pp;
    switch (field) {
        case FIELD_type: pp->setType(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_sourceId: pp->setSourceId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'OspfPacket'", field);
    }
}

const char *OspfPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr OspfPacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    OspfPacket *pp = omnetpp::fromAnyPtr<OspfPacket>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void OspfPacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    OspfPacket *pp = omnetpp::fromAnyPtr<OspfPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'OspfPacket'", field);
    }
}

Register_Class(HelloPacket)

HelloPacket::HelloPacket(const char *name, short kind) : ::OspfPacket(name, kind)
{
}

HelloPacket::HelloPacket(const HelloPacket& other) : ::OspfPacket(other)
{
    copy(other);
}

HelloPacket::~HelloPacket()
{
    delete [] this->neighborList;
}

HelloPacket& HelloPacket::operator=(const HelloPacket& other)
{
    if (this == &other) return *this;
    ::OspfPacket::operator=(other);
    copy(other);
    return *this;
}

void HelloPacket::copy(const HelloPacket& other)
{
    delete [] this->neighborList;
    this->neighborList = (other.neighborList_arraysize==0) ? nullptr : new int[other.neighborList_arraysize];
    neighborList_arraysize = other.neighborList_arraysize;
    for (size_t i = 0; i < neighborList_arraysize; i++) {
        this->neighborList[i] = other.neighborList[i];
    }
}

void HelloPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::OspfPacket::parsimPack(b);
    b->pack(neighborList_arraysize);
    doParsimArrayPacking(b,this->neighborList,neighborList_arraysize);
}

void HelloPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::OspfPacket::parsimUnpack(b);
    delete [] this->neighborList;
    b->unpack(neighborList_arraysize);
    if (neighborList_arraysize == 0) {
        this->neighborList = nullptr;
    } else {
        this->neighborList = new int[neighborList_arraysize];
        doParsimArrayUnpacking(b,this->neighborList,neighborList_arraysize);
    }
}

size_t HelloPacket::getNeighborListArraySize() const
{
    return neighborList_arraysize;
}

int HelloPacket::getNeighborList(size_t k) const
{
    if (k >= neighborList_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)neighborList_arraysize, (unsigned long)k);
    return this->neighborList[k];
}

void HelloPacket::setNeighborListArraySize(size_t newSize)
{
    int *neighborList2 = (newSize==0) ? nullptr : new int[newSize];
    size_t minSize = neighborList_arraysize < newSize ? neighborList_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        neighborList2[i] = this->neighborList[i];
    for (size_t i = minSize; i < newSize; i++)
        neighborList2[i] = 0;
    delete [] this->neighborList;
    this->neighborList = neighborList2;
    neighborList_arraysize = newSize;
}

void HelloPacket::setNeighborList(size_t k, int neighborList)
{
    if (k >= neighborList_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)neighborList_arraysize, (unsigned long)k);
    this->neighborList[k] = neighborList;
}

void HelloPacket::insertNeighborList(size_t k, int neighborList)
{
    if (k > neighborList_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)neighborList_arraysize, (unsigned long)k);
    size_t newSize = neighborList_arraysize + 1;
    int *neighborList2 = new int[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        neighborList2[i] = this->neighborList[i];
    neighborList2[k] = neighborList;
    for (i = k + 1; i < newSize; i++)
        neighborList2[i] = this->neighborList[i-1];
    delete [] this->neighborList;
    this->neighborList = neighborList2;
    neighborList_arraysize = newSize;
}

void HelloPacket::appendNeighborList(int neighborList)
{
    insertNeighborList(neighborList_arraysize, neighborList);
}

void HelloPacket::eraseNeighborList(size_t k)
{
    if (k >= neighborList_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)neighborList_arraysize, (unsigned long)k);
    size_t newSize = neighborList_arraysize - 1;
    int *neighborList2 = (newSize == 0) ? nullptr : new int[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        neighborList2[i] = this->neighborList[i];
    for (i = k; i < newSize; i++)
        neighborList2[i] = this->neighborList[i+1];
    delete [] this->neighborList;
    this->neighborList = neighborList2;
    neighborList_arraysize = newSize;
}

class HelloPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_neighborList,
    };
  public:
    HelloPacketDescriptor();
    virtual ~HelloPacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(HelloPacketDescriptor)

HelloPacketDescriptor::HelloPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(HelloPacket)), "OspfPacket")
{
    propertyNames = nullptr;
}

HelloPacketDescriptor::~HelloPacketDescriptor()
{
    delete[] propertyNames;
}

bool HelloPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<HelloPacket *>(obj)!=nullptr;
}

const char **HelloPacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *HelloPacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int HelloPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int HelloPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_neighborList
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *HelloPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "neighborList",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int HelloPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "neighborList") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *HelloPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_neighborList
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **HelloPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *HelloPacketDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int HelloPacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    HelloPacket *pp = omnetpp::fromAnyPtr<HelloPacket>(object); (void)pp;
    switch (field) {
        case FIELD_neighborList: return pp->getNeighborListArraySize();
        default: return 0;
    }
}

void HelloPacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    HelloPacket *pp = omnetpp::fromAnyPtr<HelloPacket>(object); (void)pp;
    switch (field) {
        case FIELD_neighborList: pp->setNeighborListArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'HelloPacket'", field);
    }
}

const char *HelloPacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    HelloPacket *pp = omnetpp::fromAnyPtr<HelloPacket>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string HelloPacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    HelloPacket *pp = omnetpp::fromAnyPtr<HelloPacket>(object); (void)pp;
    switch (field) {
        case FIELD_neighborList: return long2string(pp->getNeighborList(i));
        default: return "";
    }
}

void HelloPacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    HelloPacket *pp = omnetpp::fromAnyPtr<HelloPacket>(object); (void)pp;
    switch (field) {
        case FIELD_neighborList: pp->setNeighborList(i,string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'HelloPacket'", field);
    }
}

omnetpp::cValue HelloPacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    HelloPacket *pp = omnetpp::fromAnyPtr<HelloPacket>(object); (void)pp;
    switch (field) {
        case FIELD_neighborList: return pp->getNeighborList(i);
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'HelloPacket' as cValue -- field index out of range?", field);
    }
}

void HelloPacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    HelloPacket *pp = omnetpp::fromAnyPtr<HelloPacket>(object); (void)pp;
    switch (field) {
        case FIELD_neighborList: pp->setNeighborList(i,omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'HelloPacket'", field);
    }
}

const char *HelloPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr HelloPacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    HelloPacket *pp = omnetpp::fromAnyPtr<HelloPacket>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void HelloPacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    HelloPacket *pp = omnetpp::fromAnyPtr<HelloPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'HelloPacket'", field);
    }
}

Register_Class(LsaPacket)

LsaPacket::LsaPacket(const char *name, short kind) : ::OspfPacket(name, kind)
{
}

LsaPacket::LsaPacket(const LsaPacket& other) : ::OspfPacket(other)
{
    copy(other);
}

LsaPacket::~LsaPacket()
{
    delete [] this->linksKeys;
    delete [] this->linksValues;
}

LsaPacket& LsaPacket::operator=(const LsaPacket& other)
{
    if (this == &other) return *this;
    ::OspfPacket::operator=(other);
    copy(other);
    return *this;
}

void LsaPacket::copy(const LsaPacket& other)
{
    this->originId = other.originId;
    this->sequenceNumber = other.sequenceNumber;
    delete [] this->linksKeys;
    this->linksKeys = (other.linksKeys_arraysize==0) ? nullptr : new int[other.linksKeys_arraysize];
    linksKeys_arraysize = other.linksKeys_arraysize;
    for (size_t i = 0; i < linksKeys_arraysize; i++) {
        this->linksKeys[i] = other.linksKeys[i];
    }
    delete [] this->linksValues;
    this->linksValues = (other.linksValues_arraysize==0) ? nullptr : new int[other.linksValues_arraysize];
    linksValues_arraysize = other.linksValues_arraysize;
    for (size_t i = 0; i < linksValues_arraysize; i++) {
        this->linksValues[i] = other.linksValues[i];
    }
}

void LsaPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::OspfPacket::parsimPack(b);
    doParsimPacking(b,this->originId);
    doParsimPacking(b,this->sequenceNumber);
    b->pack(linksKeys_arraysize);
    doParsimArrayPacking(b,this->linksKeys,linksKeys_arraysize);
    b->pack(linksValues_arraysize);
    doParsimArrayPacking(b,this->linksValues,linksValues_arraysize);
}

void LsaPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::OspfPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->originId);
    doParsimUnpacking(b,this->sequenceNumber);
    delete [] this->linksKeys;
    b->unpack(linksKeys_arraysize);
    if (linksKeys_arraysize == 0) {
        this->linksKeys = nullptr;
    } else {
        this->linksKeys = new int[linksKeys_arraysize];
        doParsimArrayUnpacking(b,this->linksKeys,linksKeys_arraysize);
    }
    delete [] this->linksValues;
    b->unpack(linksValues_arraysize);
    if (linksValues_arraysize == 0) {
        this->linksValues = nullptr;
    } else {
        this->linksValues = new int[linksValues_arraysize];
        doParsimArrayUnpacking(b,this->linksValues,linksValues_arraysize);
    }
}

int LsaPacket::getOriginId() const
{
    return this->originId;
}

void LsaPacket::setOriginId(int originId)
{
    this->originId = originId;
}

int LsaPacket::getSequenceNumber() const
{
    return this->sequenceNumber;
}

void LsaPacket::setSequenceNumber(int sequenceNumber)
{
    this->sequenceNumber = sequenceNumber;
}

size_t LsaPacket::getLinksKeysArraySize() const
{
    return linksKeys_arraysize;
}

int LsaPacket::getLinksKeys(size_t k) const
{
    if (k >= linksKeys_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)linksKeys_arraysize, (unsigned long)k);
    return this->linksKeys[k];
}

void LsaPacket::setLinksKeysArraySize(size_t newSize)
{
    int *linksKeys2 = (newSize==0) ? nullptr : new int[newSize];
    size_t minSize = linksKeys_arraysize < newSize ? linksKeys_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        linksKeys2[i] = this->linksKeys[i];
    for (size_t i = minSize; i < newSize; i++)
        linksKeys2[i] = 0;
    delete [] this->linksKeys;
    this->linksKeys = linksKeys2;
    linksKeys_arraysize = newSize;
}

void LsaPacket::setLinksKeys(size_t k, int linksKeys)
{
    if (k >= linksKeys_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)linksKeys_arraysize, (unsigned long)k);
    this->linksKeys[k] = linksKeys;
}

void LsaPacket::insertLinksKeys(size_t k, int linksKeys)
{
    if (k > linksKeys_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)linksKeys_arraysize, (unsigned long)k);
    size_t newSize = linksKeys_arraysize + 1;
    int *linksKeys2 = new int[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        linksKeys2[i] = this->linksKeys[i];
    linksKeys2[k] = linksKeys;
    for (i = k + 1; i < newSize; i++)
        linksKeys2[i] = this->linksKeys[i-1];
    delete [] this->linksKeys;
    this->linksKeys = linksKeys2;
    linksKeys_arraysize = newSize;
}

void LsaPacket::appendLinksKeys(int linksKeys)
{
    insertLinksKeys(linksKeys_arraysize, linksKeys);
}

void LsaPacket::eraseLinksKeys(size_t k)
{
    if (k >= linksKeys_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)linksKeys_arraysize, (unsigned long)k);
    size_t newSize = linksKeys_arraysize - 1;
    int *linksKeys2 = (newSize == 0) ? nullptr : new int[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        linksKeys2[i] = this->linksKeys[i];
    for (i = k; i < newSize; i++)
        linksKeys2[i] = this->linksKeys[i+1];
    delete [] this->linksKeys;
    this->linksKeys = linksKeys2;
    linksKeys_arraysize = newSize;
}

size_t LsaPacket::getLinksValuesArraySize() const
{
    return linksValues_arraysize;
}

int LsaPacket::getLinksValues(size_t k) const
{
    if (k >= linksValues_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)linksValues_arraysize, (unsigned long)k);
    return this->linksValues[k];
}

void LsaPacket::setLinksValuesArraySize(size_t newSize)
{
    int *linksValues2 = (newSize==0) ? nullptr : new int[newSize];
    size_t minSize = linksValues_arraysize < newSize ? linksValues_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        linksValues2[i] = this->linksValues[i];
    for (size_t i = minSize; i < newSize; i++)
        linksValues2[i] = 0;
    delete [] this->linksValues;
    this->linksValues = linksValues2;
    linksValues_arraysize = newSize;
}

void LsaPacket::setLinksValues(size_t k, int linksValues)
{
    if (k >= linksValues_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)linksValues_arraysize, (unsigned long)k);
    this->linksValues[k] = linksValues;
}

void LsaPacket::insertLinksValues(size_t k, int linksValues)
{
    if (k > linksValues_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)linksValues_arraysize, (unsigned long)k);
    size_t newSize = linksValues_arraysize + 1;
    int *linksValues2 = new int[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        linksValues2[i] = this->linksValues[i];
    linksValues2[k] = linksValues;
    for (i = k + 1; i < newSize; i++)
        linksValues2[i] = this->linksValues[i-1];
    delete [] this->linksValues;
    this->linksValues = linksValues2;
    linksValues_arraysize = newSize;
}

void LsaPacket::appendLinksValues(int linksValues)
{
    insertLinksValues(linksValues_arraysize, linksValues);
}

void LsaPacket::eraseLinksValues(size_t k)
{
    if (k >= linksValues_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)linksValues_arraysize, (unsigned long)k);
    size_t newSize = linksValues_arraysize - 1;
    int *linksValues2 = (newSize == 0) ? nullptr : new int[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        linksValues2[i] = this->linksValues[i];
    for (i = k; i < newSize; i++)
        linksValues2[i] = this->linksValues[i+1];
    delete [] this->linksValues;
    this->linksValues = linksValues2;
    linksValues_arraysize = newSize;
}

class LsaPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_originId,
        FIELD_sequenceNumber,
        FIELD_linksKeys,
        FIELD_linksValues,
    };
  public:
    LsaPacketDescriptor();
    virtual ~LsaPacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(LsaPacketDescriptor)

LsaPacketDescriptor::LsaPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(LsaPacket)), "OspfPacket")
{
    propertyNames = nullptr;
}

LsaPacketDescriptor::~LsaPacketDescriptor()
{
    delete[] propertyNames;
}

bool LsaPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LsaPacket *>(obj)!=nullptr;
}

const char **LsaPacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *LsaPacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int LsaPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 4+base->getFieldCount() : 4;
}

unsigned int LsaPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_originId
        FD_ISEDITABLE,    // FIELD_sequenceNumber
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_linksKeys
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_linksValues
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *LsaPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "originId",
        "sequenceNumber",
        "linksKeys",
        "linksValues",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int LsaPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "originId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "sequenceNumber") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "linksKeys") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "linksValues") == 0) return baseIndex + 3;
    return base ? base->findField(fieldName) : -1;
}

const char *LsaPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_originId
        "int",    // FIELD_sequenceNumber
        "int",    // FIELD_linksKeys
        "int",    // FIELD_linksValues
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **LsaPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *LsaPacketDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int LsaPacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    LsaPacket *pp = omnetpp::fromAnyPtr<LsaPacket>(object); (void)pp;
    switch (field) {
        case FIELD_linksKeys: return pp->getLinksKeysArraySize();
        case FIELD_linksValues: return pp->getLinksValuesArraySize();
        default: return 0;
    }
}

void LsaPacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    LsaPacket *pp = omnetpp::fromAnyPtr<LsaPacket>(object); (void)pp;
    switch (field) {
        case FIELD_linksKeys: pp->setLinksKeysArraySize(size); break;
        case FIELD_linksValues: pp->setLinksValuesArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'LsaPacket'", field);
    }
}

const char *LsaPacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    LsaPacket *pp = omnetpp::fromAnyPtr<LsaPacket>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LsaPacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    LsaPacket *pp = omnetpp::fromAnyPtr<LsaPacket>(object); (void)pp;
    switch (field) {
        case FIELD_originId: return long2string(pp->getOriginId());
        case FIELD_sequenceNumber: return long2string(pp->getSequenceNumber());
        case FIELD_linksKeys: return long2string(pp->getLinksKeys(i));
        case FIELD_linksValues: return long2string(pp->getLinksValues(i));
        default: return "";
    }
}

void LsaPacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    LsaPacket *pp = omnetpp::fromAnyPtr<LsaPacket>(object); (void)pp;
    switch (field) {
        case FIELD_originId: pp->setOriginId(string2long(value)); break;
        case FIELD_sequenceNumber: pp->setSequenceNumber(string2long(value)); break;
        case FIELD_linksKeys: pp->setLinksKeys(i,string2long(value)); break;
        case FIELD_linksValues: pp->setLinksValues(i,string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LsaPacket'", field);
    }
}

omnetpp::cValue LsaPacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    LsaPacket *pp = omnetpp::fromAnyPtr<LsaPacket>(object); (void)pp;
    switch (field) {
        case FIELD_originId: return pp->getOriginId();
        case FIELD_sequenceNumber: return pp->getSequenceNumber();
        case FIELD_linksKeys: return pp->getLinksKeys(i);
        case FIELD_linksValues: return pp->getLinksValues(i);
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'LsaPacket' as cValue -- field index out of range?", field);
    }
}

void LsaPacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    LsaPacket *pp = omnetpp::fromAnyPtr<LsaPacket>(object); (void)pp;
    switch (field) {
        case FIELD_originId: pp->setOriginId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_sequenceNumber: pp->setSequenceNumber(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_linksKeys: pp->setLinksKeys(i,omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_linksValues: pp->setLinksValues(i,omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LsaPacket'", field);
    }
}

const char *LsaPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr LsaPacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    LsaPacket *pp = omnetpp::fromAnyPtr<LsaPacket>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void LsaPacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    LsaPacket *pp = omnetpp::fromAnyPtr<LsaPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LsaPacket'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

