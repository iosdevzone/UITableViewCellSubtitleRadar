# UITableViewCellSubtitleRadar
Code submitted to Apple to demo bug in UITableViewCell (Subtitle type) from Storyboard.

Summary:
UITableViewCells of type UITableViewCellStyleSubtitle do not display correctly if the contents of the subtitle can sometimes be nil.

Steps to Reproduce:
Run the attached project and scroll. Note that in some cases cells that claim they ought to have a subtitle do not display it. Touch one of these cells and drag (to avoid a segue) and note the subtitle appears. Rotating the device will also cause the subtitles to reappear. 

1) Create a master/view project
2) In the Main.storyboard choose the 'Master Scene' that contains the UITableView and set the style of the prototype cell to subtitle.
3) Edit MasterViewController.m altering the methods as shown below

```
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
return 1000;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"Cell" forIndexPath:indexPath];

uint32_t nRows = (uint32_t)[self tableView:self.tableView  numberOfRowsInSection:0];
if(arc4random_uniform(nRows*2) > nRows) {
cell.textLabel.text = @"Subtitle";
cell.detailTextLabel.text = @"This is a subtitle";
}
else {
cell.textLabel.text = @"No Subtitle";
cell.detailTextLabel.text = nil;
}
return cell;
}
```

Expected Results:
Subtitles shoul appear then cell.detailTextLabel.text is non-nil.

Actual Results:
For recycled cells the subtitle will not appear until a selection or rotation causes a layout pass.

Regression:
This is a regression from 7.1.1 (11D201). Confirmed occuring in 8.2 (12D5480a), 8.3 (12F701) and 8.4.1 (12H321). 


