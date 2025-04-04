import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;
import java.io.File;
import org.xml.sax.SAXParseException;


class XMLValidator{
    private boolean isValid = true;
    XMLValidator(String xmlFilePath){
        validateXML(xmlFilePath);
    }
    private void validateXML(String xmlFilePath) {
        try {
            // Create a SAXParserFactory  to validate against DTD
            SAXParserFactory factory = SAXParserFactory.newInstance();
            factory.setValidating(true);

            // Create a SAXParser
            SAXParser saxParser = factory.newSAXParser();
            // Set an error handler
            DefaultHandler handler = new DefaultHandler() {
                @Override
                public void error(SAXParseException e) throws SAXException {
                    System.out.println("Error: " + e.getMessage());
                    isValid = false; // Set flag to false if an error occurs
                }
                @Override
                public void fatalError(SAXParseException e) throws SAXException {
                    System.out.println("Fatal Error: " + e.getMessage());
                    isValid = false; // Set flag to false if a fatal error occurs
                }
                @Override
                public void warning(SAXParseException e) throws SAXException {
                    System.out.println("Warning: " + e.getMessage());
                }
            };

            saxParser.parse(new File(xmlFilePath), handler);    

            // Print validity message only if no errors occurred
            if (isValid) {
                System.out.println("XML is valid against the DTD.");
            }else{
                System.out.println("XML is not valid against the DTD.");
            }
        } catch (SAXException e) {
            System.out.println("XML is NOT valid. Error: " + e.getMessage());
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}


class main{
    public static void main(String[] args) {
        String xmlFilePath = "question.xml";
        new XMLValidator(xmlFilePath);
    }   
}
