package parser;

public class dataStruct {
	
	String macAddress = null;
	int errorCodes [] = null;
	public String getMacAddress() {
		return macAddress;
	}
	public void setMacAddress(String macAddress) {
		this.macAddress = macAddress;
	}
	public int[] getErrorCodes() {
		return errorCodes;
	}
	public void setErrorCodes(int[] errorCodes) {
		this.errorCodes = errorCodes;
	}
	
	public dataStruct(String macAddress, int[] errorCodes) {
		super();
		this.macAddress = macAddress;
		this.errorCodes = errorCodes;
	}
	
	
	
	
}
