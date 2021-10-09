package Project1;

public class Date212 {
	private int year;
	private int month;
	private int day;
	
	public Date212(String date) {
		this.year = Integer.parseInt(date.substring(0, 3));
		this.month = Integer.parseInt(date.substring(4, 5));
		this.day = Integer.parseInt(date.substring(6, 7));
	}

	public int getYear() {
		return year;
	}

	public void setYear(int year) {
		this.year = year;
	}

	public int getMonth() {
		return month;
	}

	public void setMonth(int month) {
		this.month = month;
	}

	public int getDay() {
		return day;
	}

	public void setDay(int day) {
		this.day = day;
	}

	@Override
	public String toString() {
		static String months[] =
		    {
		        null , "January" , "February" , "March" , "April", "May",
		        "June", "July", "August", "September", "October",
		        "November", "December"
		    };
		return months[month] + " " + day + ", " + year;
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + day;
		result = prime * result + month;
		result = prime * result + year;
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Date212 other = (Date212) obj;
		if (day != other.day)
			return false;
		if (month != other.month)
			return false;
		if (year != other.year)
			return false;
		return true;
	}
}
