"""
Please write your name
@author:

"""

# Reminder: You are only allowed to import the csv module (done it for you).
# OTHER MODULES ARE NOT ALLOWED (NO OTHER IMPORT!!!).

import csv


class Diabetes:

    def __init__(self, filepath) -> None:
        # Try opening the file as read specified by file path...
        try:
            with open(filepath, "r") as csv_file:
                reader = csv.reader(csv_file)
                # Store the header data in the local attribute "header"
                self.header = next(reader)
                # Store the body data in the local attribute "data"
                self.data = list(reader)
        # Except if file cannot be opened, raise FileNotFoundError
        except FileNotFoundError:
            raise FileNotFoundError


    def get_dimension(self) -> list:
        # Return the dimensions of the header and data variables in list form
        rows = len(self.data)
        columns = len(self.header)
        return [rows, columns]

    def web_summary(self, filepath: str) -> None:
        # Declare empty string "htmlData" to hold all HTML code
        # that is concatenated throughout this function 
        htmlData = ""
        # Set the foundations for the HTML file - e.g. head and body
        htmlData += "<html>\n"
        htmlData += "<head>\n<meta charset=\"UTF-8\">\n"
        htmlData += "<style>\n"
        htmlData += "table {border-collapse: collapse;}\n"
        htmlData += "table, th, td {border: 1px solid black;}\n"
        htmlData += "th, td {padding: 0 10px;}\n"
        htmlData += "</style>\n"
        htmlData += "</head>\n"
        htmlData += "<body>\n"
        htmlData += "<table>\n"
        htmlData += "<thead>\n"
        htmlData += "<tr>\n"
        htmlData += "<th rowspan=\"3\">Attributes</th>\n"
        htmlData += "<th colspan=\"4\">Class</th>\n"
        htmlData += "</tr>\n"
        htmlData += "<tr>\n"
        htmlData += "<th colspan=\"2\">Positive</th>\n"
        htmlData += "<th colspan=\"2\">Negative</th>\n"
        htmlData += "</tr>\n"
        htmlData += "<tr>\n"
        htmlData += "<th>Yes</th>\n"
        htmlData += "<th>No</th>\n"
        htmlData += "<th>Yes</th>\n"
        htmlData += "<th>No</th>\n"
        htmlData += "</tr>\n"
        htmlData += "</thead>\n"   

        attributes = self.header[2:-1]

        summary_data = {}
        for attribute in attributes:
            summary_data[attribute] = {"Positive": {"Yes": 0, "No": 0}, "Negative": {"Yes": 0, "No": 0}}

        for row in self.data:
            class_bool = row[-1]
            for i, attribute_val in enumerate(row[2:-1]):
                if attribute_val.lower() == "yes":
                    summary_data[attributes[i]][class_bool]["Yes"] += 1
                else:
                    summary_data[attributes[i]][class_bool]["No"] += 1

        htmlData += "<tbody>\n"

        for attribute in summary_data:
            htmlData += "<tr>\n"
            htmlData += f"<td>{attribute.title()}</td>\n"
            htmlData += f"<td>{summary_data[attribute]['Positive']['Yes']}</td>\n"
            htmlData += f"<td>{summary_data[attribute]['Positive']['No']}</td>\n"
            htmlData += f"<td>{summary_data[attribute]['Negative']['Yes']}</td>\n"
            htmlData += f"<td>{summary_data[attribute]['Negative']['No']}</td>\n"
            htmlData += "</tr>"
        
        htmlData += "</tbody>\n"
        
        htmlData += "</table>\n"

        with open(filepath, "w") as html:
            html.write(htmlData)
                


    def count_instances(self, **criteria) -> int:
        """
        Counts the number of instances that meet the specific search criteria.

        Arg:
            **criteria: Dictionary data type representing search criteria 
                        in the form key=value.

        Return:
            int: the count of instances that meet the specific search criteria.
        """

        for criterion in criteria:
            if criterion not in self.header:
                print(f"Invalid Criteria: '{criterion}' Not Found")
                return 0
            
        match = []

        for row in self.data:
            count = 0
            for criterion in criteria:
                if str(criteria[criterion]) == row[self.header.index(criterion)]:
                    count += 1

            if count == len(criteria):
                match.append(row)
        
        return len(match)



if __name__ == "__main__":
    # You can comment the following when you are testing your code
    # You can add more tests as you want

    # test diabetes_data.csv
    d1 = Diabetes("diabetes_data.csv")
    print(d1.get_dimension())
    d1.web_summary('stat01.html')
    print(d1.count_instances(Age=30, Name="dsgdsfdf", Gender="Female")) # change according to your criteria
    print()

    # test diabetes2_data.csv
    d2 = Diabetes("diabetes2_data.csv")
    print(d2.get_dimension())
    d2.web_summary('stat02.html')
    print(d2.count_instances(Age=41, Gender="Female", Polyuria="No"))  # change according to your criteria
