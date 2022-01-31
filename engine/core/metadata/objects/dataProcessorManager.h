#ifndef _MANAGER_DATAPROCESSOR_H__
#define _MANAGER_DATAPROCESSOR_H__

#include "dataProcessor.h"
#include "common/managerInfo.h"

class CManagerDataProcessorValue : public CValue, 
	public IMetaManagerInfo {
	wxDECLARE_DYNAMIC_CLASS(CManagerDataProcessorValue);
public:

	virtual CMetaCommonModuleObject *GetModuleManager() const;

	CManagerDataProcessorValue(CMetaObjectDataProcessorValue *metaObject = NULL);
	virtual ~CManagerDataProcessorValue();

	virtual CMethods* GetPMethods() const { PrepareNames(); return m_methods; }; //�������� ������ �� ����� �������� ������� ���� ��������� � �������
	virtual void PrepareNames() const;                         //���� ����� ������������� ���������� ��� ������������� ���� ��������� � �������
	virtual CValue Method(methodArg_t &aParams);//����� ������

	//Get ref class 
	virtual CLASS_ID GetTypeID() const;

	//types 
	virtual wxString GetTypeString() const;
	virtual wxString GetString() const;

protected:

	CMethods *m_methods;
	CMetaObjectDataProcessorValue *m_metaObject;
};

class CManagerExternalDataProcessorValue : public CValue {
	wxDECLARE_DYNAMIC_CLASS(CManagerExternalDataProcessorValue);
public:
	CManagerExternalDataProcessorValue();
	virtual ~CManagerExternalDataProcessorValue();

	virtual CMethods* GetPMethods() const { PrepareNames(); return m_methods; }; //�������� ������ �� ����� �������� ������� ���� ��������� � �������
	virtual void PrepareNames() const;                         //���� ����� ������������� ���������� ��� ������������� ���� ��������� � �������
	virtual CValue Method(methodArg_t &aParams);//����� ������

	//types 
	virtual wxString GetTypeString() const;
	virtual wxString GetString() const;

protected:
	CMethods *m_methods;
};

#endif 