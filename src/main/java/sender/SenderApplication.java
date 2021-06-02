package sender;

public class SenderApplication
{
    public static void main( String[] args )
    {
    	IDataProvider streamData = new SederDataService();
      streamData.getBMSData(15);
    }
}