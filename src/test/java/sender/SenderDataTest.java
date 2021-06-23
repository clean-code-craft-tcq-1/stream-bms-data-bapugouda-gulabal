package sender;

import java.util.List;

import org.junit.Assert;
import org.junit.Test;

import sender.SederDataService;

public class SenderDataTest {
	
	SederDataService senderData = new SederDataService();

	
	@Test
	public void getBMSDataTest() {
		List<String> data = senderData.getBMSData(10);
		Assert.assertEquals(10, data.size());
	}
	
	// Test to check the data size for a given user input 0
	@Test
	public void getBMSDataTest_Variant1() {
		Assert.assertNull(senderData.getBMSData(0));
	}
	
	//Test to check the data size for a given negative user input
	@Test
	public void getBMSDataTest_Variant2() {
		Assert.assertNull(senderData.getBMSData(-5));
		
	}
}
