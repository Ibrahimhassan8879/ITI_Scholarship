-- Lab 9 Adventure Works Part
USE AdventureWorks2012

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
--9) Display all the data from the Employee table (HumanResources Schema)
		--As an XML document “Use XML Raw”. “Use Adventure works DB”
		--A) Elements
		--B) Attributes -- this means it appears beside the tag like in-line attributes in html
		--  the default display option is attribute


		-- IMPORTANT ===>  to diplay a mix of both elements and attributes... we would have to use other words than 'raw'
		

use AdventureWorks2012

-- AS Elements 
select * from HumanResources.Employee
for xml raw('Employee'),ELEMENTS xsinil,ROOT('AdventrureWorks_Employee')

-- AS attributes
select * from HumanResources.Employee
for xml raw('Employee')
