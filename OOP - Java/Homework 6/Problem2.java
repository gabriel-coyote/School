//Gabriel Coyote

import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.geometry.Pos;
import javafx.geometry.Insets;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.control.Button;
import javafx.event.EventHandler;
import javafx.event.ActionEvent;

public class Problem2 extends Application{
	//Fields
	private TextField PropertyValue_TextField;
	private Label result_Label;
	
	
	public static void main(String[] args) {
		//Launch the application
		launch(args);
	}
	
	//Override
	public void start(Stage primaryStage) {
		//Crate a Label to display a prompt
		Label promptLabel = new Label("Enter Property Actual Value:");
		//Create a TextField for input
		PropertyValue_TextField = new TextField();
		
		
		//Create a Button to perform Conversion
		Button calcButton = new Button("Display Assessment Value & Property Tax");
		//Register the event handler
		calcButton.setOnAction(new CalcButtonHandler());
		
		//Create a empty Label to display the result
		result_Label = new Label();
		
		//Put the promptLabel(s) and the TextField in an HBox
		HBox hbox = new HBox(10, promptLabel, PropertyValue_TextField);

		
		// Put the HBox, calcButton, and resultLabel in a VBox.
	      VBox vbox = new VBox(10, hbox, calcButton,result_Label);
	      
	      
	    // Set the VBox's alignment to center.
	    vbox.setAlignment(Pos.CENTER);
	      
	    // Set the VBox's padding to 10 pixels.
	    vbox.setPadding(new Insets(10));
	      
	    // Create a Scene.
	    Scene scene = new Scene(vbox);

	    // Add the Scene to the Stage.
	    primaryStage.setScene(scene);
	    
	    // Set the stage title.
	      primaryStage.setTitle("Property Taxes :( ");
	      
	      // Show the window.
	      primaryStage.show();  	
	}
	
	
	
	class CalcButtonHandler implements EventHandler<ActionEvent>
	{
	   //Override
	   public void handle(ActionEvent event)
	   {
	      // Get the Property Value
	      Double PropertyValue = Double.parseDouble(PropertyValue_TextField.getText());
	
	     
	      // Calculate Assessment Value and Property Tax
	      Double assessmentValue = PropertyValue * .60;
	      Double propertyTax = assessmentValue / 100 * .64;
	      
	      
	      // Display the results.
	      result_Label.setText(String.format("Assessment Value: $ %,.2f "+'\n'+"Property Tax: $ %,.2f", assessmentValue, propertyTax));
	   }
	}
}
