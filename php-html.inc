<?php
	class html_page {
		private $head;	
		private $body;
		function html_title($title) {
			$this->head = '		<title>'.$title.'</title>'."\r\n";
			$this->head .= '		<meta http-equiv="content-type" content="text/html; charset=UTF-8">'."\r\n";
		}
		function html_head($head_str) {
			$this->head .= '		'.$head_str."\r\n";
		}
		function html_style($sheet) {
			$this->head .= '		<link rel="stylesheet" type="text/css" href="'.$sheet.'">'."\r\n";
		}
		function html_jshead($js_file) {
			$this->head .= '		<script type="text/javascript" src="'.$js_file.'"></script>'."\r\n";
		}
		function html_jsfile($js_file) {
			$this->body .= '		<script type="text/javascript" src="'.$js_file.'"></script>'."\r\n";
		}
		function html_js($js) {
			$this->body .= '		<script type="text/javascript" >'."\r\n";
			$this->body .= $js.'		</script>'."\r\n";
		}
		function html_iframe($src,$name) {
			$iframe_str = '			<iframe src="'.$src.'" name="'.$name.'" frameborder="0">'."\r\n";
			$iframe_str .= '				Your Browser does not support frames'."\r\n";
			$iframe_str .= '			</iframe>'."\r\n";
			$this->body .= $iframe_str;
		}
		function html_label($caption,$class="",$id="") {
			$label_str = '		<div';
			if (!empty($class)) { $label_str .= ' class="'.$class.'"'; }
			if (!empty($id)) { $label_str .= ' id="'.$id.'"'; }
			$label_str .= '>'."\r\n"."			".$caption."\r\n";
			$label_str .= '		</div>'."\r\n";
			$this->body .= $label_str;
		}
		function html_label_nobr($caption,$class="",$id="") {
			$label_str = '		<div';
			if (!empty($class)) { $label_str .= ' class="'.$class.'"'; }
			if (!empty($id)) { $label_str .= ' id="'.$id.'"'; }
			$label_str .= '>'."\r\n".$caption."\r\n";
			$label_str .= '		</div>'."\r\n";
			$this->body .= $label_str;
		}
		function html_render() {
			echo '<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">'."\r\n";
			echo '<html>'."\r\n";
			echo '	<head>'."\r\n".$this->head.'	</head>'."\r\n";
			echo '	<body>'."\r\n".$this->body.'	</body>'."\r\n";
			echo '</html>';
		}
	}
	class html_table {
		private $table_str;
		private $lvl;
		function __construct($class="",$level_arg) {
			$this->lvl = $level_arg;
			$this->table_str = '<table';
			if (!empty($class)) { $this->table_str .= ' class="'.$class.'"'; }
			$this->table_str .= '>'."\r\n";	
		}
		function table_row($td_arr,$class="") {
			$row_str = get_tabs($this->lvl).'<tr';
			if (!empty($class)) { $row_str .= ' class="'.$class.'"'; }
			$row_str .= '>'."\r\n";	
			foreach ($td_arr as $td) {
				$colspan = strstr($td,"colspan");
				if (empty($colspan)) {
					$row_str .= get_tabs($this->lvl+1).'<td>'.$td.'</td>'."\r\n";
				} else {
					$row_str .= get_tabs($this->lvl+1).'<td colspan="'.substr($colspan,-1).'">'.substr($td,0,strlen($td)-8).'</td>'."\r\n";
				}
			}
			$row_str .= get_tabs($this->lvl).'</tr>'."\r\n";
			$this->table_str .= $row_str;
		}
		function table_end() {
			$this->table_str .= get_tabs($this->lvl-1).'</table>';
			return $this->table_str;
		}
	}
	class html_form {
		private $form_str;
		private $lvl;
		function __construct($action,$level_arg,$method="post") {
			$this->lvl = $level_arg;
			$this->form_str = '<form method="'.$method.'" action="'.$action.'">'."\r\n";
		}
		function input($name,$length=NULL,$pass=NULL,$initial=NULL,$class=NULL) {
			$pass==true ? $type = "password" : $type = "text";
			if (empty($class)) {
				$this->form_str .= get_tabs($this->lvl).'<input type="'.$type.'" name="'.$name.'">'."\r\n";
			} else {
				$this->form_str .= get_tabs($this->lvl).'<input type="'.$type.'" name="'.$name.'" class="'.$class.'">'."\r\n";
			}
		}
		function text($text="",$class) {
			if (empty($class)) {
				$this->form_str .= get_tabs($this->lvl).$text."\r\n";
			} else {
				$this->form_str .= get_tabs($this->lvl).'<span class="'.$class.'">'.$text.'</span>'."\r\n";
			}
		}
		function force_br() {
			$this->form_str .= get_tabs($this->lvl).'<br>'."\r\n";
		}
		function hidden($name,$value) {
			$this->form_str .= get_tabs($this->lvl).'<input type="hidden" name="'.$name.'" value="'.$value.'">'."\r\n";
		}
		function dropdown($name,$options) {
			$this->form_str .= get_tabs($this->lvl).'<select name="'.$name.'" size="1">'."\r\n";
			$this->form_str .= $options."\r\n";
			$this->form_str .= get_tabs($this->lvl).'</select>'."\r\n";
			
		}
		function submit($caption) {
			if (empty($caption)) {
				$this->form_str .= get_tabs($this->lvl).'<input type="submit">'."\r\n";
			} else {
				$this->form_str .= get_tabs($this->lvl).'<input type="submit" value="'.$caption.'">'."\r\n";
			}
		}
		function form_end() {
			$this->form_str .= get_tabs($this->lvl-1).'</form>'."\r\n";
			return $this->form_str;
		}
	}
	function get_tabs($level) {
		$tabs = "";
		for ($i=0;$i<$level;$i++) {
			$tabs .= "	";
		}
		return $tabs;
	}
?>
