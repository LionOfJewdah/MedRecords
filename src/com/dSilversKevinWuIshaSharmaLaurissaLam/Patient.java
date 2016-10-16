package com.dSilversKevinWuIshaSharmaLaurissaLam;

import java.util.Date;

public class Patient extends Person {
	
	protected sex mGender;
	protected Person[] mNextOfKin;
	protected HealthCareProvider primaryCarePhysician;
	protected HealthCareProvider[] authorisedDoctors;
	
	public Person[] getKin() {
		return mNextOfKin;
	}
	
	public void authorise(HealthCareProvider doctorDude) {
		
	}
	
	Patient(String name, Date birthdate, int socSec, sex gender) {
		super(name, birthdate, socSec);
		mGender = gender;
	}
	
}
