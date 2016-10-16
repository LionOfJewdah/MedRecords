package com.dSilversKevinWuIshaSharmaLaurissaLam;

import java.util.Date;

public class Person {

	protected String _name;
	protected Date _dob;
	protected int _ID;
	
	public String getName() {
		return _name;
	}
	
	public Date getDate( ) {
		return _dob;
	}
	
	public int getID() {
		return _ID;
	}
	
	Person(String name, Date birthdate, int socSec) {
		_name = name;
		_dob = birthdate;
		_ID = socSec;
	}
	
};
