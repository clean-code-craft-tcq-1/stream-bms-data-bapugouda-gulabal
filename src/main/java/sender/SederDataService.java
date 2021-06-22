package sender;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class SederDataService implements IDataProvider {

		Random random = new Random();

		private int getRandomValue(int minValue, int maxValue) {
			return random.nextInt(maxValue - minValue) + minValue;
		}

		private int getTemperature() {
			return getRandomValue(SenderDataConstants.LOWER_TEMPERATURE, SenderDataConstants.HIGHER_TEMPERATURE);
		}

		private int getStateOfCharge() {
			return getRandomValue(SenderDataConstants.LOWER_SOC, SenderDataConstants.HIGHER_SOC);
		}

		private String getValue() {
			StringBuilder bmsData = new StringBuilder();
			bmsData.append(SenderDataConstants.TEMPERTAURE + ":" + getTemperature());
			bmsData.append("|");
			bmsData.append(SenderDataConstants.STATE_OF_CHARGE + ":" + getStateOfCharge());
			return bmsData.toString();
		}

		public List<String> getBMSData(int numberOfData) {
			if (numberOfData <= 0) {
				return null;
			}
			List<String> bmsData = new ArrayList<String>();
			String value = null;
			while (numberOfData-- > 0) {
				value = getValue();
				bmsData.add(value);
				printValue(value);

			}
			return bmsData;
		}

		private void printValue(String value) {
			System.out.println(value);
		}

	}

