#ifndef _TYPE_DESCRIPTION_H__
#define _TYPE_DESCRIPTION_H__

#include "value.h"
#include "common/attributeInfo.h"

class CValueTypeDescription : public CValue {
	wxDECLARE_DYNAMIC_CLASS_NO_COPY(CValueTypeDescription);
private:
	static CMethods m_methods;
	std::vector<CLASS_ID> m_aTypes;
public:
	CValueQualifierNumber *m_qNumber;
	CValueQualifierDate *m_qDate;
	CValueQualifierString *m_qString;
public:
	//��� ������ ����� �������������� � ����� ���������� ��������:
	virtual CMethods* GetPMethods() const { return &m_methods; };//�������� ������ �� ����� �������� ������� ���� ��������� � �������
	virtual void PrepareNames() const;//���� ����� ������������� ���������� ��� ������������� ���� ��������� � �������
	virtual CValue Method(methodArg_t &aParams);//����� ������
public:

	CValueTypeDescription(); 

	CValueTypeDescription(class CValueType *valueType); 
	CValueTypeDescription(class CValueType *valueType,
		CValueQualifierNumber *qNumber, CValueQualifierDate *qDate, CValueQualifierString *qString);

	CValueTypeDescription(const CLASS_ID &clsid); 
	CValueTypeDescription(const CLASS_ID &clsid,
		CValueQualifierNumber *qNumber, CValueQualifierDate *qDate, CValueQualifierString *qString);

	virtual ~CValueTypeDescription();

	virtual bool Init() { return false; }
	virtual bool Init(CValue **aParams);

	virtual wxString GetTypeString() const { return wxT("typeDescription"); }
	virtual wxString GetString() const { return wxT("typeDescription"); }

public:
	std::vector<CLASS_ID> GetLongTypes() { return m_aTypes; }
public:

	bool ContainsType(const CValue &cType) const;
	CValue AdjustValue() const;
	CValue AdjustValue(const CValue &cVal) const;
	CValue Types() const;
};

#endif 