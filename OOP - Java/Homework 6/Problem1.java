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

public class Problem1 extends Application{
	//Fields
	private TextField WholeSale_TextField;
	private TextField MarkupPercentage_TextField;
	private Label result_RetailPrice_Label;
	
	
	public static void main(String[] args) {
		//Launch the application
		launch(args);
	}
	
	//Override
	public void start(Stage primaryStage) {
		//Crate a Label to display a prompt
		Label promptLabel = new Label("Enter WholeSale Cost of item:");
		//Create a TextField for input
		WholeSale_TextField = new TextField();
		
		//Crate a Label to display a prompt
		Label promptLabel2 = new Label("Enter Markup Percentage:");
		//Create a TextField for input
		MarkupPercentage_TextField = new TextField();
		
		//Create a Button to perform Conversion
		Button calcButton = new Button("Display Item's Retail Price");
		//Register the event handler
		calcButton.setOnAction(new CalcButtonHandler());
		
		//Create a empty Label to display the result
		result_RetailPrice_Label = new Label();
		
		//Put the promptLabel(s) and the TextField in an HBox
		HBox hbox = new HBox(10, promptLabel, WholeSale_TextField);
		HBox hbox2 = new HBox(10, promptLabel2,  MarkupPercentage_TextField);
		
		// Put the HBox, calcButton, and resultLabel in a VBox.
	      VBox vbox = new VBox(10, hbox, hbox2, calcButton,result_RetailPrice_Label);
	      
	      
	    // Set the VBox's alignment to center.
	    vbox.setAlignment(Pos.CENTER);
	      
	    // Set the VBox's padding to 10 pixels.
	    vbox.setPadding(new Insets(10));
	      
	    // Create a Scene.
	    Scene scene = new Scene(vbox);

	    // Add the Scene to the Stage.
	    primaryStage.setScene(scene);
	    
	    // Set the stage title.
	      primaryStage.setTitle("Wholesale & Markup to Retail Price Converter");
	      
	      // Show the window.
	      primaryStage.show();  	
	}
	
	
	
	class CalcButtonHandler implements EventHandler<ActionEvent>
	{
	   //Override
	   public void handle(ActionEvent event)
	   {
	      // Get the wholesale cost and MarkUp Percentage
	      Double wholesale_cost = Double.parseDouble(WholeSale_TextField.getText());
	      Double markUp_percent = Double.parseDouble(MarkupPercentage_TextField.getText());
	      
	      
	      // Calculate Retail Price
	      Double RetailPrice = wholesale_cost + (wholesale_cost * (markUp_percent / 100));
	      
	      
	      // Display the results.
	      result_RetailPrice_Label.setText(String.format("$ %,.2f ", RetailPrice));
	   }
	}
}



