#pragma once
#include <string>
#include <stdint.h>
#include <stdio.h>
#include <iostream>
#include <ostream>
#include <list>




namespace MyDesignPattern
{
	class Component
	{
	public:
		Component(std::string strDescription, std::string strName) : strDescription_(strDescription), strName_(strName)
		{
			
		}
		virtual ~Component()
		{
			
		}
		virtual void vAdd(std::shared_ptr <MyDesignPattern::Component> component)
		{
			
		}
		virtual void vRemove(std::shared_ptr <MyDesignPattern::Component> component)
		{
			
		}
		virtual bool bIsDepartment() const
		{
			return false;
		}
		virtual std::string strGetDescriptionAndName(std::string strBefore) const = 0;
	protected:
		std::string strName_;
		std::string strDescription_;
	};

	class Department : public Component
	{
	public:
		Department(std::string strDescription, std::string strName) : Component(strDescription, strName)
		{
			
		}
		virtual void vAdd(std::shared_ptr <MyDesignPattern::Component> component) override
		{
			children_.push_back(component);
		}
		virtual void vRemove(std::shared_ptr <MyDesignPattern::Component> component) override
		{
			children_.remove(component);
		}
		virtual bool bIsDepartment() const override
		{
			return true;
		}
		virtual std::string strGetDescriptionAndName(std::string strBefore) const override
		{
			std::string strReturn = (strBefore + strDescription_ + "-" + strName_ + "\n");

			for ( auto ait : children_)
			{
				strReturn = strReturn + ait->strGetDescriptionAndName(strBefore + "---");
			}
			return strReturn;
		}
	protected:
	private:
		std::list<std::shared_ptr<Component>> children_;
	};

	class Employee : public Component
	{
	public:
		Employee(std::string strDescription, std::string strName) : Component{ strDescription, strName }
		{

		}
		std::string strGetDescriptionAndName(std::string strBefore) const override
		{
			return (strBefore + strDescription_ + "-" + strName_ + "\n");
		}
	protected:
	private:

	};

}