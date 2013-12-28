<?php
	include("include/header.php");
?>

<!-- ------------ main window to code ----------- -->
<div id="GridRuleHolder">
 	<div id="GridWindow">
		<?php
			include("SudokuGrid.php");
		?>
	</div>

	<div id="RuleWindow" >
<br/>
<br/>
Sudoku  is a logic-based, combinatorial number-placement puzzle. The objective is to fill a 9*9 grid with digits so that each column, each row, and each of the nine 3*3 sub-grids that compose the grid (also called "boxes", "blocks", "regions", or "sub-squares") contains all of the digits from 1 to 9. The puzzle  typically has a unique solution.
<br/>
<br/>

	<form method="post"  id="subscibe_form">
	<div><input name="solve" id="lesolve" type="submit" value="Solve" class="button" onclick="Solve()"/>
	</div></form>

	</div>

</div>

<!--  ------------ main window End Here -----------  -->

<?php
	include("include/footer.php");
?>
