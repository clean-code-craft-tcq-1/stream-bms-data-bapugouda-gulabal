package sender;

public class SenderApp 
{
    public static void main( String[] args )
    {
    	IDataProvider streamData = new SederDataService();
      streamData.getBMSData(15);
    }
}